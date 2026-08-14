/**
   @file examples/src/iganet_multipatch.cxx

   @brief Demonstration of IgANet multipatch structure

   This example demonstrates how to load a multi-patch XML.

   @author Matthias Moller

   @copyright This file is part of the IgANet project

   This Source Code Form is subject to the terms of the Mozilla Public
   License, v. 2.0. If a copy of the MPL was not distributed with this
   file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <common.hpp>
#include <iganet.h>
#include <iostream>

using namespace iganet::literals;
using namespace torch::indexing;

int main() {
  iganet::init();
  iganet::Log.setLogLevel(iganet::log::verbose);

  using real_t = double;
  using patch_t = iganet::BSplinePatch<real_t, 3, 2>;
  using multipatch_t = iganet::MultiPatch<patch_t>;

  auto filename = iganet::getDataPath("surfaces/g_plus_s_surf.xml");
  
  pugi::xml_document document;
  const pugi::xml_parse_result result = document.load_file(filename.c_str());

  if (!result)
    throw std::runtime_error(
                             "Cannot read '" + filename.string() + "': " + result.description());

  const auto options =
    iganet::Options<real_t>{}
    .device(torch::kCPU)
    .requires_grad(false);

  multipatch_t multipatch;
  multipatch.from_xml(document, 0, "", -1, options);

  std::cout << "Patches:    " << multipatch.npatches() << '\n';
  std::cout << "Interfaces: " << multipatch.ninterfaces() << '\n';

  for (std::size_t i = 0; i < multipatch.ninterfaces(); ++i) {
    const auto &interface = multipatch.interface(i);

    std::cout << "Interface " << i << ": patch "
              << multipatch.findPatchIndex(interface.firstPatch())
              << " side " << interface.firstSide() << " <-> patch "
              << multipatch.findPatchIndex(interface.secondPatch())
              << " side " << interface.secondSide() << '\n';
  }

  auto json = multipatch.to_json();

  multipatch_t mp;

  mp.from_json(json, options);
  
  iganet::finalize();
  return 0;
}

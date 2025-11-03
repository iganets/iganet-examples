# IGAnets-Examples

[![GitlabSync](https://github.com/iganets/iganet-examples/actions/workflows/gitlab-sync.yml/badge.svg)](https://github.com/iganets/iganet-examples/actions/workflows/gitlab-sync.yml)
[![CMake on multiple platforms](https://github.com/iganets/iganet-examples/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/iganets/iganet-examples/actions/workflows/cmake-multi-platform.yml)
[![Documentation](https://img.shields.io/badge/docs-mkdocs-blue.svg)](https://iganets.github.io/iganet/)

[![GitHub Releases](https://img.shields.io/github/release/iganets/iganet-examples.svg)](https://github.com/iganets/iganet-examples/releases)
[![GitHub Downloads](https://img.shields.io/github/downloads/iganets/iganet-examples/total)](https://github.com/iganets/iganet-examples/releases)
[![GitHub Issues](https://img.shields.io/github/issues/iganets/iganet-examples.svg)](https://github.com/iganets/iganet-examples/issues)

This repository contains example applications for [IGAnets](https://github.com/iganets/iganet), a novel approach to combine the concept of deep operator learning with the mathematical framework of isogeometric analysis.

## Usage instructions

This repository can be used in two modes:

1. As standalone example applications by running CMake on _this_ repository without flags

2. As optional module in [iganets::core](https://github.com/iganets/iganet) by running CMake on the [iganets::core](https://github.com/iganets/iganet) repository with the flag
   ```
   -DIGANET_OPTIONAL="examples"
   ```

3. Compile the code
   ```shell
   make
   ```

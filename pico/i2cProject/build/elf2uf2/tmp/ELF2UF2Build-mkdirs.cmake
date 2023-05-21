# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-sdk/tools/elf2uf2"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/tmp"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/src/ELF2UF2Build-stamp"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/src"
  "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/colinenck/CS/repos/Embedded-Software/pico/pico-project-generator/i2cProject/build/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()

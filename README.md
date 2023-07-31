# ELFDecoder
Executable and Linkable Format decoder

## How to build:
```
$ cmake . && make
```

## Project structure:
```
ELFDecoder
├── lib                - directory with library sources
│   ├── inc            - directory with library headers
│   │   └── elfdecoder.h   - main decoder library header
│   └── src            - directory with library sources
│       └── elfdecoder.cpp - main decoder library sources file
├── samples            - directory with binary samples
│   └── simple.bin     - simple elf file
├── doc                - directory with documentation and information
│   └── ELF_Format.pdf - ELF format description
├── README.md          - project description
└── main.cpp           - main project source file
```

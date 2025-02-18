#include <windows.h>
#include <vector>
#include <string>

// EBCDIC to ASCII conversion table
const unsigned char EBCDIC_TO_ASCII[256] = {
    /* 00 */ 0x00, 0x01, 0x02, 0x03, 0x9C, 0x09, 0x86, 0x7F,
    /* 08 */ 0x97, 0x8D, 0x8E, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    /* 10 */ 0x10, 0x11, 0x12, 0x13, 0x9D, 0x85, 0x08, 0x87,
    /* 18 */ 0x18, 0x19, 0x92, 0x8F, 0x1C, 0x1D, 0x1E, 0x1F,
    /* 20 */ 0x80, 0x81, 0x82, 0x83, 0x84, 0x0A, 0x17, 0x1B,
    /* 28 */ 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x05, 0x06, 0x07,
    /* 30 */ 0x90, 0x91, 0x16, 0x93, 0x94, 0x95, 0x96, 0x04,
    /* 38 */ 0x98, 0x99, 0x9A, 0x9B, 0x14, 0x15, 0x9E, 0x1A,
    /* 40 */ 0x20, 0xA0, 0xE2, 0xE4, 0xE0, 0xE1, 0xE3, 0xE5,
    /* 48 */ 0xE7, 0xF1, 0xC4, 0xD6, 0xC9, 0x64, 0x50, 0x7C,
    /* 50 */ 0xC2, 0xD2, 0xC3, 0xD1, 0xD5, 0xFD, 0x7F, 0x7D,
    /* 58 */ 0x61, 0x5C, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
    /* 60 */ 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
    /* 68 */ 0x4F, 0x5A, 0x5B, 0x5D, 0x5E, 0x5F, 0x6A, 0x6B,
    /* 70 */ 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73,
    /* 78 */ 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    // Remaining mappings go here...
};

std::string ConvertEBCDICtoASCII(const std::string& input) {
    std::string output;
    output.reserve(input.size());

    for (unsigned char c : input) {
        output.push_back(EBCDIC_TO_ASCII[c]);
    }

    return output;
}

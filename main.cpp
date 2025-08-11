#include <iostream>
#include "Huffman.h"
#include "utils.h"

int main()
{
    std::string text = readFile("input.txt");
    Huffman huffman;
    huffman.build(text);

    std::string encoded = huffman.encode(text);
    writeFile("compressed.bin", encoded);

    std::string decoded = huffman.decode(encoded);
    writeFile("decompressed.txt", decoded);

    std::cout << "Original size: " << text.size() * 8 << " bits\n";
    std::cout << "Compressed size: " << encoded.size() << " bits\n";
    std::cout << "Decompression successful: " << (text == decoded ? "Yes" : "No") << "\n";
}
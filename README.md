Huffman Compression CLI      

  A command-line tool to compress and decompress files using the Huffman Coding algorithm.
  This project implements lossless data compression, reducing file size while preserving the original data.

Features
  1. Lossless compression with Huffman Coding.
  2. Fast encoding and decoding using a priority queue and binary tree.
  3. Simple CLI interface for ease of use.
  4. Cross-platform support.

How It Works
  1. Reads the input file and calculates the frequency of each character.
  2. Builds a Huffman tree, assigning shorter codes to frequent characters.
  3. Encodes the file into a binary .huff format for compression.
  4. Decodes .huff files back into the original text without any data loss.


Usage
  1. Compression     
     ./huffman compress file.txt out.huff
     
  3. Decompression     
     ./huffman decompress out.huff recovered.txt

   
Tech Stack
  1. Language: C++
  2. Algorithm: Huffman Coding
  3. Build Tools: GCC
  4. Interface: Command Line Arguments





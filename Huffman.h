#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f, Node *l = nullptr, Node *r = nullptr);
};

struct Compare
{
    bool operator()(Node *l, Node *r);
};

class Huffman
{
public:
    void build(const std::string &text);
    std::string encode(const std::string &text);
    std::string decode(const std::string &encoded);

private:
    Node *root;
    std::unordered_map<char, std::string> huffmanCode;
    void buildCode(Node *node, const std::string &str);
    void freeTree(Node *node);
};

#endif

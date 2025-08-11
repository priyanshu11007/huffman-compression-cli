#include "Huffman.h"
#include <iostream>

Node::Node(char c, int f, Node *l, Node *r) : ch(c), freq(f), left(l), right(r) {}

bool Compare::operator()(Node *l, Node *r)
{
    return l->freq > r->freq;
}

void Huffman::build(const std::string &text)
{
    std::unordered_map<char, int> freq;
    for (char c : text)
        freq[c]++;

    std::priority_queue<Node *, std::vector<Node *>, Compare> pq;
    for (auto &pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }
    root = pq.top();
    buildCode(root, "");
}

void Huffman::buildCode(Node *node, const std::string &str)
{
    if (!node)
        return;
    if (!node->left && !node->right)
        huffmanCode[node->ch] = str;
    buildCode(node->left, str + "0");
    buildCode(node->right, str + "1");
}

std::string Huffman::encode(const std::string &text)
{
    std::string encoded;
    for (char c : text)
        encoded += huffmanCode[c];
    return encoded;
}

std::string Huffman::decode(const std::string &encoded)
{
    std::string decoded;
    Node *curr = root;
    for (char bit : encoded)
    {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right)
        {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

void Huffman::freeTree(Node *node)
{
    if (!node)
        return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}
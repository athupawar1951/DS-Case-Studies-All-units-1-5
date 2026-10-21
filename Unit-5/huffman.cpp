#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <functional>
using namespace std;

// Unit 5 Case Study B: Frequency-based Huffman encoding.
// This demo encodes and decodes text in memory; it is not a full ZIP/GZIP file writer.

struct HuffmanNode {
    char ch;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char character, int count)
        : ch(character), frequency(count), left(nullptr), right(nullptr) {}
    HuffmanNode(HuffmanNode* l, HuffmanNode* r)
        : ch('\\0'), frequency(l->frequency + r->frequency), left(l), right(r) {}
};

struct CompareNodes {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) const {
        return a->frequency > b->frequency;
    }
};

void deleteTree(HuffmanNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void buildCodes(HuffmanNode* node, const string& prefix,
                unordered_map<char,string>& codes) {
    if (!node) return;
    if (!node->left && !node->right) {
        codes[node->ch] = prefix.empty() ? "0" : prefix;
        return;
    }
    buildCodes(node->left, prefix + "0", codes);
    buildCodes(node->right, prefix + "1", codes);
}

HuffmanNode* buildTree(const string& text) {
    unordered_map<char,int> frequencies;
    for (unsigned char ch : text) frequencies[(char)ch]++;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
    for (const auto& item : frequencies)
        pq.push(new HuffmanNode(item.first, item.second));

    if (pq.empty()) return nullptr;
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        pq.push(new HuffmanNode(left, right));
    }
    return pq.top();
}

string encodeText(const string& text, const unordered_map<char,string>& codes) {
    string encoded;
    for (char ch : text) encoded += codes.at(ch);
    return encoded;
}

string decodeBits(const string& bits, HuffmanNode* root) {
    string decoded;
    if (!root) return decoded;

    // Special case: input contained only one unique character.
    if (!root->left && !root->right) {
        for (char bit : bits) {
            if (bit == '0') decoded += root->ch;
            else {
                cout << "Invalid bit in encoded data.\\n";
                return "";
            }
        }
        return decoded;
    }

    HuffmanNode* current = root;
    for (char bit : bits) {
        if (bit == '0') current = current->left;
        else if (bit == '1') current = current->right;
        else {
            cout << "Encoded data must contain only 0 and 1.\\n";
            return "";
        }

        if (!current) {
            cout << "Invalid encoded bit sequence.\\n";
            return "";
        }

        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    if (current != root)
        cout << "Warning: encoded data ended mid-code.\\n";
    return decoded;
}

int main() {
    cout << "===== HUFFMAN TEXT ENCODING DEMO =====\\n";
    cout << "Enter a line of text: ";
    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "No text entered. Nothing to encode.\\n";
        return 0;
    }

    HuffmanNode* root = buildTree(input);
    unordered_map<char,string> codes;
    buildCodes(root, "", codes);

    cout << "\\nCharacter frequencies and Huffman codes:\\n";
    for (const auto& item : codes) {
        char ch = item.first;
        cout << (ch == ' ' ? "[space]" : string(1, ch))
             << " : frequency " << count(input.begin(), input.end(), ch)
             << ", code " << item.second << '\\n';
    }

    string encoded = encodeText(input, codes);
    string decoded = decodeBits(encoded, root);

    cout << "\\nOriginal text: " << input << '\\n';
    cout << "Encoded bits:  " << encoded << '\\n';
    cout << "Decoded text:  " << decoded << '\\n';
    cout << "Original size (8-bit characters, approximate): "
         << input.size() * 8 << " bits\\n";
    cout << "Encoded size (not including tree/header): "
         << encoded.size() << " bits\\n";
    cout << "Note: a real compressed file must also store the code tree/frequency table.\\n";

    deleteTree(root);
    return 0;
}

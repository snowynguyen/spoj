#include <bits/stdc++.h>
using namespace std;

const int Z = 26;

struct TrieNode {
    bool isEnd;
    TrieNode* child[Z];

    TrieNode() {
        isEnd = false;
        
        for (int i=0; i<Z; ++i) {
            child[i] = nullptr;
        }
    }
}root;


int main() {

}
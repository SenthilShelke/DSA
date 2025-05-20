#include <iostream>
#include <bitset>
using namespace std;

int normal_to_block(int i, int j, int n) {
    int block_i = i/2; // i >> 1
    int block_j = j/2; // j >> 1
    int block_index = block_i * (n/2) + block_j;
    int within_block_i = i % 2;
    int within_block_j = j % 2;
    int within_block_index = within_block_i * 2 + within_block_j;
    return block_index * 4 + within_block_index;
}



int main() {
    int m = 8; 
    int n = 8; 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = normal_to_block(i, j, n);
            cout << "M(" << i << "," << j << ") = " << idx << " = " << std::bitset<4>(idx)<< endl;
        }
    }

    return 0;
} 

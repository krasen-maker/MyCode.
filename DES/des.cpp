#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Функция пока что получает битовое значение ключа (размер 64 бит)
unsigned long k64_to58(string key){
    int n = key.length();
    if (n>8){
        cout << "Your key is too large. Enter the key which contains less than 8 char"; // пока так сделаю.
        return -1;
    }
    bitset<64> bit_k;
    
    for(int i = 0; i < n;i=i+1){
        bit_k=bit_k | bitset<64>(key[i])<<(56-8*i);
    };
    cout << bit_k << endl;
    string k58 = bit_k.to_string();
    cout << k58.length() << endl;
    for(int i = 1;i<=8;i++){
        cout << "Step " << i << ": " << 8*i-1 << endl;
        k58.erase(8*i-i,1);
    }
    cout << "Stop!" << endl;
    cout << k58.length() << endl;
    
    return 0;
}


int main()
{
    string k = "qwerty";
    unsigned long key =  k64_to58(k);
    return 0;
}

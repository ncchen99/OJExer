#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int primeNumbers[4792];
    primeNumbers[0] = 2;
    int amount = 0;
    for (int i = 3; i < 46338; i+=2) {
        bool prime = true;
        for (int j = 0; primeNumbers[j] <= sqrt(i); j++) {
            if (i % primeNumbers[j] == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            amount += 1;
            primeNumbers[amount] = i;
        }
    }
    int checkNum;
    while (cin>>checkNum) {
        bool isPrime = true;
        if (checkNum <= 46337) {
            if (!binary_search(primeNumbers, primeNumbers + amount+1, checkNum)) {
                isPrime = false;
            }
        } else {
            for (int i = 0; i < 4792 && isPrime; i++) {
                if (checkNum % primeNumbers[i] == 0)
                    isPrime = false;
            }
        }
        cout<<(isPrime ? "質數" : "非質數")<<"\n";
    }
}

#include <stdio.h>
#include <math.h>

// Greatest common denominator
int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main() {

    // 2 random prime numbers
    int p = 2;
    int q = 7;

    // this is the modulus, and is publicly available
    int n = p * q;

    // number of common factors of n
    int totient = (p - 1) * (q - 1);

    // choose e ;:  1 > e < totient & e is coprime with n and totient
    int publicKey = 2;

    // for checking co-prime with publicKey > 1
    while (publicKey < totient) {
        if (gcd(publicKey, totient) == 1)
            break;
        else
            publicKey++;
    }

    int plaintext = 12;

    // lock = pair<int, int>{publicKey, n}
    int cipherText = fmod(pow(plaintext, publicKey), n);

    // choose privateKey s.t.: mod(privateKey * publicKey, totient) == 1
    int privateKey = 1;
//    while(fmod((privateKey * publicKey), totient) != 1)

    for (int i = 1; i < n; i++)
    {
        privateKey++;
    }


    int message = fmod(pow(cipherText, privateKey), n);

    printf("\nplaintext = %d\n", plaintext);
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = pq = %d\n", n);
    printf("totient = %d\n\n", totient);
    printf("publicKey = %d\n", publicKey);
    printf("privateKey = %d\n\n", privateKey);
    printf("cipherText = %d\n", cipherText);
    printf("message = %d\n", message);

    return 0;
}
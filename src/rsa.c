#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isprime(long long int n)
{
    if (n > 1)
    {
        int counter = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                counter++;
                if (counter > 2)
                {
                    return 0;
                    break;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int gcd(long long int a, long long int b)
{

    long long int tmp;
    while (a % b != 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}
long long int mod_exp(long long int c, long long int d, long long int N) {
    long long int result = 1;
    c = c % N;
    while (d > 0) {
        if (d % 2 == 1) {
            result = (result * c) % N;
        }
        d = d >> 1;
        c = (c * c) % N;
    }
    return result;
}
int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
    }
    else
    {
        if (strcmp(argv[1], "enc") == 0 || strcmp(argv[1], "dec") == 0) {
            long long int e = atoll(argv[2]), d = atoll(argv[3]), p = atoll(argv[4]), q = atoll(argv[5]);

            // Checking if all intigers are positive numbers and p and q are prime numbers
            if (e > 0 && d > 0 && p > 0 && q > 0)
            {
                if (isprime(p) && isprime(q))
                {
                    long long int N = p * q;
                    long long int phi = (p-1)*(q-1); // Φ(N) = Φ(p*q) = Φ(p)*Φ(q) = (p-1)*(q-1) because p and q are prime numbers so Φ(q) = q-1 and Φ(p) = p-1.
                    if (gcd(e, phi) == 1)
                    {
                        if (e * d % phi == 1)
                        {
                            long long int m;
                            if (scanf("%lld", &m) != 1) {return 1;}
                            if (m < N || m <= 0) {
                                if (m > 0) {
                                    if (strcmp(argv[1], "enc") == 0) {
                                        printf("%llu\n", mod_exp(m, e, N));
                                    }
                                    else {
                                        printf("%llu\n", mod_exp(m, d, N));
                                    }
                                    return 0;
                                }
                                else {
                                    printf("Negative numbers are not allowed!\n");
                                }
                            }
                            else {
                                printf("Message is larger than N\n");
                            }
                        }
                        else {
                            printf("e * d mod phi(N) is not 1\n");
                        }
                    }
                    else {
                        printf("e is not coprime with phi(N)\n");
                    }
                }
                else {
                    printf("p and q must be prime\n");
                }
            }
            else {
                printf("Negative numbers are not allowed\n");
            }
        }
        else {
            printf("First argument must be 'enc' or 'dec'\n");
        }
    }
    return 1;
}

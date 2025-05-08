# RSA Encryption/Decryption Program


### Author

- **Panagiotis Vardalas**

## Overview

This C program implements basic **RSA encryption** and **decryption**. It allows users to securely encrypt and decrypt messages using RSA algorithm, requiring two prime numbers and their corresponding public and private exponents.
  
## Usage

Once compiled, you can use the program to either encrypt or decrypt a message. The program takes the following syntax:

```sh
echo message | ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>
```

Where:

- ``message``: The message you want to encrypt or decrypt.
- ``enc`` or ``dec``: Specifies whether you want to encrypt or decrypt.
- ``<exp_exp>``: The public exponent e for encryption (or decryption exponent d for decryption).
- ``<priv_exp>``: The private exponent d for decryption (or public exponent e for encryption).
- ``<prime1>``: The first prime number p.
- ``<prime2>``: The second prime number q.

## Example:

```sh
echo 42 | ./rsa enc 7 23 61 53
```

### To encrypt a message:

1) First, the program will take an intiger for input (message) m to encrypt.
2) If the input is valid and less than N (the product of p and q), the program will return the encrypted message.

### Decrypting a message:

### To decrypt a message using the private exponent d:

```sh
echo 42 | ./rsa dec 7 23 61 53
```

The program will decrypt the previously encrypted message.


## How It Works

- **Input Validation:** The program ensures that all provided arguments are positive integers, and checks that the prime numbers p and q are indeed prime.
- **Public and Private Exponent Relationship:** The program checks that e and d are valid by ensuring e * d % phi(N) == 1, where phi(N) is Euler's totient function.
- **Encryption/Decryption:** Using the mod_exp() function, the program computes the modular exponentiation of the message m with either e or d and prints the resulting encrypted or decrypted message.

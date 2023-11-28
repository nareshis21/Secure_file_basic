

# Secure File Manager

The Secure File Manager is a command-line utility for encrypting and decrypting files using a password-derived key. It provides a simple and secure way to protect your sensitive data.

## Features

- **Encryption**: Securely encrypt your files using a password.
- **Decryption**: Easily decrypt the files using the same password.

## Prerequisites

- C++ compiler (e.g., g++)
- Bash shell

## Getting Started

1. **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/secure-file-manager.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd secure-file-manager
    ```

3. **Compile the source files:**

    ```bash
    g++ -c encrypt/encryptModule.cpp -o encryptModule.o
    g++ -c decrypt/decryptModule.cpp -o decryptModule.o
    g++ -c main/mainModule.cpp -o mainModule.o
    g++ encryptModule.o decryptModule.o mainModule.o -o SecureFileManager
    ```

4. **Run the program:**

    ```bash
    ./SecureFileManager
    ```

## Usage

1. **Main Menu:**

    - Choose option `1` to Encrypt or Decrypt a file.
    - Choose option `2` to exit the program.

2. **Encrypt or Decrypt Menu:**

    - Enter the file name.
    - Enter the password.
    - Choose an operation:
        - `1` to Encrypt
        - `2` to Decrypt
        - `3` to go back to the Main Menu.

3. **Exit:**

    - Choose option `2` from the Main Menu.

## Tips

- Choose a strong and memorable password to enhance the security of your encrypted files.
- Back up your password or keep it in a secure place. If you forget it, you won't be able to decrypt your files.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

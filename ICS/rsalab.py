import rsa
if __name__ == "__main__":
    publickey,privatekey = rsa.newkeys(512)
    print(publickey)
    print("\n")
    print(privatekey)
    message = b'Hello, world!'
    crypto = rsa.encrypt(message,publickey)
    print("\n")
    print(f"Encrypted Message: {crypto}")
    message = rsa.decrypt(crypto,privatekey)
    print("\n")
    print(f"Decrypted Message: {message}")
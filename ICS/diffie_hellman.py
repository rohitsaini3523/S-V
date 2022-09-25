#implement diffie hellman key exchange
def diffie_hellman(p,g,a,b):
    A = (g**a)%p
    B = (g**b)%p
    keyA = (B**a)%p
    keyB = (A**b)%p
    return keyA,keyB

def main():
    p = 23
    g = 9
    a = 4
    b = 3
    keyA,keyB = diffie_hellman(p,g,a,b)
    print(keyA,keyB)
def test():
    pass
def debug():
    pass
if __name__ == "__main__":
    main()
    test()
    debug()

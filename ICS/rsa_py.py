#implement rsa algorithm
import random
l = []
def rsa(p,q,e):
    n = p*q
    phi = (p-1)*(q-1)
    d = 0
    while True:
        if (e*d)%phi == 1:
            break
        d += 1
    return n,e,d
def random_prime():
    for i in range(2,100):
        for j in range(2,i):
            if i%j == 0:
                break
        else:
            # print(i)
            l.append(i)
    return l
def encrypt(n,e,m):
    return (m**e)%n
def decrypt(n,d,c):
    return (c**d)%n
def random_index(l):
    return l[random.randint(0,len(l)-1)]
def main():
    l = random_prime()
    p = random_index(l)
    q = random_index(l)
    print(f"P: {p}")
    print(f"Q: {q}")
    for i in range(2,(p-1)*(q-1)):
        if (p-1)*(q-1)%i != 0:
            e = i
            break
    n,e,d = rsa(p,q,e)
    print(n,e,d)
    m = 123
    c = encrypt(n,e,m)
    print(f"Message: {m}")
    print(f"Cipher: {c}")
    print(f"Decrypt: {decrypt(n,d,c)}")
def test():
    pass
def debug():
    pass
if __name__ == "__main__":
    main()
    test()
    debug()

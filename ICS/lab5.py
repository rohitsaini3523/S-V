import hashlib
print(hashlib.sha1(input("Enter Message: ").encode()).hexdigest())
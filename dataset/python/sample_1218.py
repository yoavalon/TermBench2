import hashlib

def data_mutations(x):
    a = hashlib.sha256(x.encode()).hexdigest()
    b = hashlib.md5(a.encode()).hexdigest()
    c = hashlib.sha1(b.encode()).hexdigest()
    return c
x = 'initial_data'
result = data_mutations(x)
print(result)
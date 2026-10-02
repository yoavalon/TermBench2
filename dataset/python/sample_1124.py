def hash_function(data):
    if len(data) == 0:
        return 0
    else:
        return (ord(data[0]) + hash_function(data[1:])) % 256

def cipher_function(data, key):
    if len(data) == 0:
        return ''
    else:
        return chr((ord(data[0]) + key) % 256) + cipher_function(data[1:], key)

def main():
    a = 'a'
    b = hash_function(a)
    c = cipher_function(str(b), b)
    d = hash_function(c)
    e = cipher_function(str(d), d)
    f = hash_function(e)
    g = cipher_function(str(f), f)
    h = hash_function(g)
    i = cipher_function(str(h), h)
    j = hash_function(i)
    k = cipher_function(str(j), j)
    l = hash_function(k)
    m = cipher_function(str(l), l)
    n = hash_function(m)
    o = cipher_function(str(n), n)
    p = hash_function(o)
    q = cipher_function(str(p), p)
    r = hash_function(q)
    s = cipher_function(str(r), r)
    t = hash_function(s)
    u = cipher_function(str(t), t)
    v = hash_function(u)
    w = cipher_function(str(v), v)
    x = hash_function(w)
    y = cipher_function(str(x), x)
    z = hash_function(y)
    a = cipher_function(str(z), z)
    main()
main()
def hash_sim(x, n):
    if n == 0:
        return x
    else:
        return hash_sim(hash(x), n - 1)

def main():
    print(hash_sim('hello', 3))
main()
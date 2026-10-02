def hash_simulate(x, n):
    if n == 0:
        return x
    else:
        return hash_simulate(x + hash(x), n - 1)

def main():
    result = hash_simulate(0, 3)
    print(result)
main()
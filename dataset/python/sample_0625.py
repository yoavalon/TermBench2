def consensus(a, b):
    if a == b:
        return a
    if a > b:
        return consensus(a - 1, b)
    return consensus(a, b - 1)

def main():
    result = consensus(4, 5)
    print(result)
main()
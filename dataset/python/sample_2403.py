def sequence(a, b, n):
    if n == 0:
        return a
    elif n == 1:
        return b
    else:
        return sequence(b, a + b, n - 1)

def main():
    a, b, n = (0, 1, 10)
    result = sequence(a, b, n)
    print(result)
main()
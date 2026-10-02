def f(a, b, c):
    if a > b:
        return c
    else:
        return f(a + 1, b, c + 1)

def main():
    result = f(1, 10, 0)
    print(result)
main()
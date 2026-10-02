def func(x, n):
    if n == 0:
        return 1
    else:
        return x * func(x, n - 1)

def main():
    result = func(2.0, 10)
    print(result)
main()
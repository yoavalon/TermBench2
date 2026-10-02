def f(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        return float('inf')

def main():
    result = f(1.0, 2.0)
    print(result)
main()
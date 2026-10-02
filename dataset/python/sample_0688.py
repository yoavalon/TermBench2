def a(b, c, d):
    if b <= 0 or c <= 0 or d <= 0:
        return 0
    if b == 1 and c == 1 and (d == 1):
        return 1
    return a(b - 1, c, d) + a(b, c - 1, d) + a(b, c, d - 1)

def main():
    print(a(3, 3, 3))
main()
def main():
    a = [1]
    while True:
        b = a[-1]
        a.append(b + 1)
        print(a[-1])
main()
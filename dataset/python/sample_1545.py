def main():
    a = 'AGCTAGCTAGCT'
    b = 'AGCTCGCTAGCT'
    i = 0
    while True:
        if i < len(a):
            if a[i] != b[i]:
                a = a[:i] + b[i] + a[i + 1:]
            i += 1
        else:
            i = 0
main()
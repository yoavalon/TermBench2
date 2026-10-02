def main():
    a = 0.1 + 0.2
    b = 0.3
    c = a - b
    if c < 1e-09:
        print('Equal')
    else:
        print('Not equal')
main()
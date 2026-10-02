def simulate():
    a = 0.1
    b = 0.2
    while True:
        c = a + b
        if c == 0.3:
            print(c)
        else:
            print(f'{c} != 0.3')
simulate()
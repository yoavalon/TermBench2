def state_machine():
    a, b, c = (0.1, 0.2, 0.3)
    while True:
        d = a + b
        if d == c:
            print('1')
        else:
            print('0')
state_machine()
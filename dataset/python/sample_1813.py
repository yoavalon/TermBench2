def state_machine(data):
    a, b, c = (0.0, 0.0, 0.0)
    for _ in range(len(data)):
        a, b, c = (b, c, a + b + c + data[_])
    return c
if __name__ == '__main__':
    state_machine([1.1, 2.2, 3.3])
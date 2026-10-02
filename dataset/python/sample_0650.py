def simulate(x, y, t):
    if t == 0:
        return
    for i in range(x):
        for j in range(y):
            if (i + j) % 2 == 0:
                print('*', end='')
            else:
                print('.', end='')
        print()
    simulate(x, y, t - 1)
simulate(5, 5, 3)
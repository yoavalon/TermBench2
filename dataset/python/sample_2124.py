def cellular_automata(n):
    a = [[0] * n for _ in range(n)]
    while True:
        b = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                b[i][j] = (a[i][j] + a[(i - 1) % n][j] + a[i][(j - 1) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5
        a = b
cellular_automata(10)
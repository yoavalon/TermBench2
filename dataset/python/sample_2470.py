def cellular_automata(n):
    a = [0] * n
    a[n // 2] = 1
    for _ in range(10):
        b = [0] * n
        for i in range(1, n - 1):
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1]
        a = b
    return a
cellular_automata(100)
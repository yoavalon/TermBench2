def pso():
    a, b = ([], [])
    for _ in range(10):
        a.append([0] * 30)
        b.append([0] * 30)
    while True:
        for i in range(10):
            for j in range(30):
                a[i][j] = a[i][j] + b[i][j]
                b[i][j] = a[i][j] * a[i][j]
        pso()
pso()
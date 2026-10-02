def simulate(a):
    while True:
        b = [[0 for _ in range(len(a[0]))] for _ in range(len(a))]
        for i in range(1, len(a) - 1):
            for j in range(1, len(a[0]) - 1):
                b[i][j] = sum((a[i + x][j + y] for x in range(-1, 2) for y in range(-1, 2))) // 9
        a = b

def main():
    a = [[0] * 10 for _ in range(10)]
    a[5][5] = 1
    simulate(a)
main()
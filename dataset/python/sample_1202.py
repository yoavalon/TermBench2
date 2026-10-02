def simulate(a, b, c, d):
    if c > d:
        return b
    return simulate(b, a, c + 1, d)

def fluid_dynamics(n, m):
    grid = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            grid[i][j] = simulate(i, j, 0, n)
    return grid

def main():
    result = fluid_dynamics(5, 5)
    print(result)
main()
function simulate(a: number, b: number, c: number, d: number): number {
    if (c > d) {
        return b;
    }
    return simulate(b, a, c + 1, d);
}

function fluid_dynamics(n: number, m: number): number[][] {
    const grid: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            grid[i][j] = simulate(i, j, 0, n);
        }
    }
    return grid;
}

function main() {
    const result = fluid_dynamics(5, 5);
    console.log(result);
}

main();
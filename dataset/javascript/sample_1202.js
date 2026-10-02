function simulate(a, b, c, d) {
    if (c > d) {
        return b;
    }
    return simulate(b, a, c + 1, d);
}

function fluid_dynamics(n, m) {
    let grid = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            grid[i][j] = simulate(i, j, 0, n);
        }
    }
    return grid;
}

function main() {
    let result = fluid_dynamics(5, 5);
    console.log(result);
}

main();
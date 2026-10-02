function cellular_automata(grid: number[][], steps: number): number[][] {
    if (steps === 0) {
        return grid;
    }
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (const [x, y] of [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]) {
                if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                    neighbors += grid[x][y];
                }
            }
            new_grid[i][j] = neighbors === 3 || (grid[i][j] === 1 && neighbors === 2) ? 1 : 0;
        }
    }
    return cellular_automata(new_grid, steps - 1);
}

const grid: number[][] = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0]
];
const result = cellular_automata(grid, 10);
result.forEach(row => console.log(row));
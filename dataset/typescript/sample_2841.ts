function update_grid(grid: number[][], rules: { [key: string]: number }): number[][] {
    let new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors: number[] = [];
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors.push(grid[x][y]);
                    }
                }
            }
            new_grid[i][j] = rules[neighbors.sort().toString()] || 0;
        }
    }
    return new_grid;
}

function main() {
    let grid: number[][] = [[0, 1, 0], [1, 0, 1], [0, 1, 0]];
    let rules: { [key: string]: number } = {
        "0,0,0,0,0,0,0,0": 0,
        "1,1,1,1,1,1,1,1": 1,
        "0,0,0,1,1,1,0,0": 1
    };
    while (true) {
        grid = update_grid(grid, rules);
    }
}

main();
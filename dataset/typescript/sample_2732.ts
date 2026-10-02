function simulate(grid: number[][], rules: number[]): void {
    while (true) {
        const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
        for (let i = 0; i < grid.length; i++) {
            for (let j = 0; j < grid[0].length; j++) {
                const neighbors: number[] = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].map(([dx, dy]) => 
                    (0 <= i + dx && i + dx < grid.length && 0 <= j + dy && j + dy < grid[0].length) ? grid[i + dx][j + dy] : 0
                );
                new_grid[i][j] = rules[neighbors.reduce((sum, val) => sum + val, 0)];
            }
        }
        grid = new_grid;
    }
}

function main(): void {
    const initial_grid: number[][] = [[0, 1, 0], [0, 0, 1], [1, 1, 1]];
    const transition_rules: number[] = [0, 1, 1, 1, 0, 0, 0, 0, 0];
    simulate(initial_grid, transition_rules);
}

main();
function updateGrid(grid: number[][], rule: (neighbors: number[], cell: number) => number): number[][] {
    const newGrid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const neighbors: number[] = [];
            for (let di of [-1, 0, 1]) {
                for (let dj of [-1, 0, 1]) {
                    if (!(di === 0 && dj === 0)) {
                        neighbors.push(grid[(i + di) % grid.length][(j + dj) % grid[0].length]);
                    }
                }
            }
            newGrid[i][j] = rule(neighbors, grid[i][j]);
        }
    }
    return newGrid;
}

function evolve(grid: number[][], rule: (neighbors: number[], cell: number) => number, steps: number): number[][] {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, rule);
    }
    return grid;
}

function main() {
    const grid: number[][] = [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ];

    const rule = (neighbors: number[], cell: number): number => {
        return sum(neighbors) === 3 ? 1 : 0;
    };

    while (true) {
        grid = evolve(grid, rule, 1);
    }
}

function sum(arr: number[]): number {
    return arr.reduce((acc, val) => acc + val, 0);
}

main();
function initGrid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        const row: number[] = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.floor(Math.random() * 2));
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = JSON.parse(JSON.stringify(grid));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (!grid[i][j] && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    let grid = initGrid(size);
    while (true) {
        grid = updateGrid(grid);
        grid.forEach(row => console.log(row.join(' ')));
        console.log('-'.repeat(40));
    }
}

main();
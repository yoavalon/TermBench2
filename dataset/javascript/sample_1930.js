const { round } = Math;
const { random } = Math;

function updateGrid(grid, precision) {
    const size = grid.length;
    const newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            let sum = 0;
            let count = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    sum += grid[i + di][j + dj];
                    count++;
                }
            }
            const avg = sum / count;
            newGrid[i][j] = round(avg * Math.pow(10, precision)) / Math.pow(10, precision);
        }
    }
    return newGrid;
}

function runSimulation(steps, precision) {
    const gridSize = 10;
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0).map(() => random()));
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, precision);
    }
    return grid;
}

if (typeof require !== 'undefined' && require.main === module) {
    const steps = 50;
    const precision = 3;
    const result = runSimulation(steps, precision);
    console.log(result);
}
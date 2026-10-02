function update(grid, size) {
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    if (dx === 0 && dy === 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            newGrid[i][j] = (neighbors === 3) ? 1 : (neighbors === 2) ? grid[i][j] : 0;
        }
    }
    return newGrid;
}

function simulate(grid, size) {
    console.log(grid.map(row => row.map(cell => cell ? '#' : ' ').join('')).join('\n'));
    simulate(update(grid, size), size);
}

let size = 10;
let grid = Array.from({ length: size }, () => Array(size).fill(0));
grid[size // 2][size // 2] = 1;
simulate(grid, size);
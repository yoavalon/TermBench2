function initializeGrid(size) {
    let grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.floor(Math.random() * 2));
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid) {
    let newGrid = JSON.parse(JSON.stringify(grid));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let gridSize = 100;
    let grid = initializeGrid(gridSize);
    let canvas = document.createElement('canvas');
    document.body.appendChild(canvas);
    let ctx = canvas.getContext('2d');
    canvas.width = gridSize;
    canvas.height = gridSize;

    function drawGrid(grid) {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        for (let i = 0; i < grid.length; i++) {
            for (let j = 0; j < grid[i].length; j++) {
                ctx.fillStyle = grid[i][j] === 1 ? 'black' : 'white';
                ctx.fillRect(j, i, 1, 1);
            }
        }
    }

    setInterval(() => {
        grid = updateGrid(grid);
        drawGrid(grid);
    }, 100);
}

main();
class Grid {
    constructor(size) {
        this.grid = Array(size).fill().map(() => Array(size).fill(0));
        this.size = size;
    }

    update() {
        let newGrid = Array(this.size).fill().map(() => Array(this.size).fill(0));
        for (let i = 1; i < this.size - 1; i++) {
            for (let j = 1; j < this.size - 1; j++) {
                let neighbors = [];
                for (let x = -1; x <= 1; x++) {
                    for (let y = -1; y <= 1; y++) {
                        neighbors.push(this.grid[i + x][j + y]);
                    }
                }
                newGrid[i][j] = this.rules(neighbors);
            }
        }
        this.grid = newGrid;
    }

    rules(neighbors) {
        let count = neighbors.reduce((sum, val) => sum + val, 0) - this.grid[1][1];
        if (this.grid[1][1] === 1 && (count < 2 || count > 3)) {
            return 0;
        } else if (this.grid[1][1] === 0 && count === 3) {
            return 1;
        }
        return this.grid[1][1];
    }
}

class BoundaryHandler {
    apply(grid) {
        for (let i = 0; i < grid.size; i++) {
            grid.grid[0][i] = grid.grid[grid.size - 2][i];
            grid.grid[grid.size - 1][i] = grid.grid[1][i];
            grid.grid[i][0] = grid.grid[i][grid.size - 2];
            grid.grid[i][grid.size - 1] = grid.grid[i][1];
        }
    }
}

class Simulator {
    constructor(grid, boundaryHandler, iterations) {
        this.grid = grid;
        this.boundaryHandler = boundaryHandler;
        this.iterations = iterations;
    }

    run() {
        for (let _ = 0; _ < this.iterations; _++) {
            this.grid.update();
            this.boundaryHandler.apply(this.grid);
        }
    }
}

function main() {
    let size = 10;
    let iterations = 50;
    let grid = new Grid(size);
    let boundaryHandler = new BoundaryHandler();
    let simulator = new Simulator(grid, boundaryHandler, iterations);
    simulator.run();
    console.log(grid.grid);
}

main();
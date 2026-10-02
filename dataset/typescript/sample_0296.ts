class Grid {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update(): void {
        const newGrid = this.grid.map(row => [...row]);
        for (let i = 1; i < this.size - 1; i++) {
            for (let j = 1; j < this.size - 1; j++) {
                const neighbors = this.getNeighbors(i, j);
                newGrid[i][j] = this.rules(neighbors);
            }
        }
        this.grid = newGrid;
    }

    getNeighbors(i: number, j: number): number[] {
        const neighbors = [];
        for (let x = i - 1; x <= i + 1; x++) {
            for (let y = j - 1; y <= j + 1; y++) {
                neighbors.push(this.grid[x][y]);
            }
        }
        return neighbors;
    }

    rules(neighbors: number[]): number {
        const count = neighbors.reduce((sum, val) => sum + val, 0) - this.grid[1][1];
        if (this.grid[1][1] === 1 && (count < 2 || count > 3)) {
            return 0;
        } else if (this.grid[1][1] === 0 && count === 3) {
            return 1;
        }
        return this.grid[1][1];
    }
}

class BoundaryHandler {
    apply(grid: Grid): void {
        grid.grid[0] = grid.grid[grid.size - 2].slice();
        grid.grid[grid.size - 1] = grid.grid[1].slice();
        for (let i = 0; i < grid.size; i++) {
            grid.grid[i][0] = grid.grid[i][grid.size - 2];
            grid.grid[i][grid.size - 1] = grid.grid[i][1];
        }
    }
}

class Simulator {
    grid: Grid;
    boundaryHandler: BoundaryHandler;
    iterations: number;

    constructor(grid: Grid, boundaryHandler: BoundaryHandler, iterations: number) {
        this.grid = grid;
        this.boundaryHandler = boundaryHandler;
        this.iterations = iterations;
    }

    run(): void {
        for (let i = 0; i < this.iterations; i++) {
            this.grid.update();
            this.boundaryHandler.apply(this.grid);
        }
    }
}

function main(): void {
    const size = 10;
    const iterations = 50;
    const grid = new Grid(size);
    const boundaryHandler = new BoundaryHandler();
    const simulator = new Simulator(grid, boundaryHandler, iterations);
    simulator.run();
    console.log(grid.grid);
}

main();
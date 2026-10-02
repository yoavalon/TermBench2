class Grid {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (this.grid[i][j] === 0 && neighbors === 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = this.grid[i][j];
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if ((i !== x || j !== y) && 0 <= i && i < this.size && 0 <= j && j < this.size) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }
}

class Simulation {
    grid: Grid;
    steps: number;

    constructor(grid: Grid) {
        this.grid = grid;
        this.steps = 0;
    }

    run(max_steps: number) {
        while (this.steps < max_steps) {
            this.grid.update();
            this.steps += 1;
        }
    }
}

function main() {
    const size = 50;
    const max_steps = 100;
    const grid = new Grid(size);
    const simulation = new Simulation(grid);
    simulation.run(max_steps);
}

main();
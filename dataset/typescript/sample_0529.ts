class Grid {
    grid: number[][];

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if ((i !== x || j !== y) && i >= 0 && i < this.grid.length && j >= 0 && j < this.grid[i].length) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }
}

class Simulation {
    grid: Grid;

    constructor(grid_size: number) {
        this.grid = new Grid(grid_size);
    }

    run() {
        while (true) {
            this.grid.update();
        }
    }
}

function main() {
    const simulation = new Simulation(10);
    simulation.run();
}

main();
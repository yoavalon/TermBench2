const random = require('random');

class Grid {
    constructor(size) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 1) {
                    new_grid[i][j] = neighbors === 2 || neighbors === 3 ? 1 : 0;
                } else {
                    new_grid[i][j] = neighbors === 3 ? 1 : 0;
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if (i !== x || j !== y) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }
}

class Simulation {
    constructor(grid_size) {
        this.grid = new Grid(grid_size);
        this.populate_grid();
    }

    populate_grid() {
        for (let i = 0; i < this.grid.size; i++) {
            for (let j = 0; j < this.grid.size; j++) {
                this.grid.grid[i][j] = random.int(0, 1);
            }
        }
    }

    run() {
        while (true) {
            this.grid.update();
        }
    }
}

function main() {
    const sim = new Simulation(10);
    sim.run();
}

main();
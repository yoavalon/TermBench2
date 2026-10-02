class FluidSimulator {
    constructor(grid_size, steps) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.steps = steps;
        this.step_count = 0;
    }

    update() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
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
        this.step_count += 1;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = x - 1; i <= x + 1; i++) {
            for (let j = y - 1; j <= y + 1; j++) {
                if ((i !== x || j !== y) && i >= 0 && i < this.grid.length && j >= 0 && j < this.grid[i].length) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }

    run() {
        if (this.step_count < this.steps) {
            this.update();
            this.run();
        }
    }
}

function main() {
    const sim = new FluidSimulator(10, 100);
    sim.run();
    sim.grid.forEach(row => console.log(row.join(' ')));
}

main();
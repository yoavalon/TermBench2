class FluidSimulator {
    grid: number[][];
    steps: number;
    step_count: number;

    constructor(grid_size: number, steps: number) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.steps = steps;
        this.step_count = 0;
    }

    update(): void {
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

    run(): void {
        if (this.step_count < this.steps) {
            this.update();
            this.run();
        }
    }
}

function main(): void {
    const sim = new FluidSimulator(10, 100);
    sim.run();
    sim.grid.forEach(row => console.log(row.join(' ')));
}

main();
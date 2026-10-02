class AutomataGrid {
    constructor(size, density) {
        this.grid = Array.from({ length: size }, () => 
            Array.from({ length: size }, () => Math.random() < density ? 1 : 0)
        );
        this.size = size;
    }

    apply_rules() {
        const new_grid = this.grid.map(row => [...row]);
        for (let i = 1; i < this.size - 1; i++) {
            for (let j = 1; j < this.size - 1; j++) {
                let neighbors = 0;
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        neighbors += this.grid[i + di][j + dj];
                    }
                }
                neighbors -= this.grid[i][j];
                if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (this.grid[i][j] === 0 && neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    set_boundary_conditions() {
        for (let i = 0; i < this.size; i++) {
            this.grid[i][0] = this.grid[i][this.size - 2];
            this.grid[i][this.size - 1] = this.grid[i][1];
        }
        for (let j = 0; j < this.size; j++) {
            this.grid[0][j] = this.grid[this.size - 2][j];
            this.grid[this.size - 1][j] = this.grid[1][j];
        }
    }
}

class Simulation {
    constructor(grid, steps) {
        this.grid = grid;
        this.steps = steps;
    }

    run() {
        for (let _ = 0; _ < this.steps; _++) {
            this.grid.apply_rules();
            this.grid.set_boundary_conditions();
        }
    }
}

function main() {
    const size = 10;
    const density = 0.3;
    const steps = 50;
    const grid = new AutomataGrid(size, density);
    const simulation = new Simulation(grid, steps);
    simulation.run();
}

main();
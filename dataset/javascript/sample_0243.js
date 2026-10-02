class Automata {
    constructor(size, boundary_type) {
        this.grid = new Array(size).fill(0).map(() => new Array(size).fill(0));
        this.boundary_type = boundary_type;
        this.size = size;
    }

    apply_boundary_conditions() {
        if (this.boundary_type === 'fixed') {
            for (let i = 0; i < this.size; i++) {
                this.grid[i][0] = 1;
                this.grid[i][this.size - 1] = 1;
            }
            for (let j = 0; j < this.size; j++) {
                this.grid[0][j] = 1;
                this.grid[this.size - 1][j] = 1;
            }
        } else if (this.boundary_type === 'periodic') {
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

    update_grid() {
        let new_grid = this.grid.map(row => [...row]);
        for (let i = 1; i < this.size - 1; i++) {
            for (let j = 1; j < this.size - 1; j++) {
                let neighbors = 0;
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        neighbors += this.grid[i + di][j + dj];
                    }
                }
                neighbors -= this.grid[i][j];
                if (this.grid[i][j] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    }
                } else if (neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        this.grid = new_grid;
    }
}

class Simulation {
    constructor(automata, steps) {
        this.automata = automata;
        this.steps = steps;
    }

    run() {
        for (let _ = 0; _ < this.steps; _++) {
            this.automata.apply_boundary_conditions();
            this.automata.update_grid();
        }
    }
}

function main() {
    let size = 10;
    let boundary_type = 'fixed';
    let steps = 50;
    let automata = new Automata(size, boundary_type);
    let simulation = new Simulation(automata, steps);
    simulation.run();
}

main();
import { randomInt } from 'crypto';

class AutomataGrid {
    grid: number[][];
    size: number;

    constructor(size: number, density: number) {
        this.grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => (randomInt(100) < density * 100 ? 1 : 0))
        );
        this.size = size;
    }

    applyRules() {
        const newGrid = this.grid.map(row => [...row]);
        for (let i = 1; i < this.size - 1; i++) {
            for (let j = 1; j < this.size - 1; j++) {
                const neighbors = this.grid[i - 1][j - 1] + this.grid[i - 1][j] + this.grid[i - 1][j + 1] +
                                  this.grid[i][j - 1] + this.grid[i][j + 1] +
                                  this.grid[i + 1][j - 1] + this.grid[i + 1][j] + this.grid[i + 1][j + 1];
                if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (this.grid[i][j] === 0 && neighbors === 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        this.grid = newGrid;
    }

    setBoundaryConditions() {
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
    grid: AutomataGrid;
    steps: number;

    constructor(grid: AutomataGrid, steps: number) {
        this.grid = grid;
        this.steps = steps;
    }

    run() {
        for (let _ = 0; _ < this.steps; _++) {
            this.grid.applyRules();
            this.grid.setBoundaryConditions();
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
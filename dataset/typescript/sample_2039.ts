import * as np from 'numpy';

class CellularAutomaton {
    grid: number[][];

    constructor(size: number) {
        this.grid = np.random.randint(0, 2, { size: [size, size] }).tolist();
    }

    update() {
        const new_grid = np.copy(this.grid).tolist();
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const neighbors = np.array(this.grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2)));
                new_grid[i][j] = Number(np.sum(neighbors) === 3 || (this.grid[i][j] === 1 && np.sum(neighbors) === 2));
            }
        }
        this.grid = new_grid;
    }

    get_state() {
        return this.grid;
    }
}

class FluidSimulator {
    size: number;
    steps: number;
    ca: CellularAutomaton;

    constructor(size: number, steps: number) {
        this.size = size;
        this.steps = steps;
        this.ca = new CellularAutomaton(size);
    }

    simulate() {
        for (let _ = 0; _ < this.steps; _++) {
            this.ca.update();
        }
    }

    get_result() {
        return this.ca.get_state();
    }
}

function main() {
    const size = 100;
    const steps = 1000;
    const simulator = new FluidSimulator(size, steps);
    simulator.simulate();
    const result = simulator.get_result();
    console.log(result);
}

main();
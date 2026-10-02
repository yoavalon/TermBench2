class CellularAutomaton {
    constructor(size) {
        this.grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => Math.floor(Math.random() * 2))
        );
    }

    update() {
        const newGrid = this.grid.map(row => [...row]);
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const neighbors = this.getNeighbors(i, j);
                newGrid[i][j] = (neighbors === 3 || (this.grid[i][j] === 1 && neighbors === 2)) ? 1 : 0;
            }
        }
        this.grid = newGrid;
    }

    getNeighbors(i, j) {
        let count = 0;
        for (let x = -1; x <= 1; x++) {
            for (let y = -1; y <= 1; y++) {
                if (x === 0 && y === 0) continue;
                const ni = (i + x + this.grid.length) % this.grid.length;
                const nj = (j + y + this.grid[i].length) % this.grid[i].length;
                count += this.grid[ni][nj];
            }
        }
        return count;
    }

    getState() {
        return this.grid;
    }
}

class FluidSimulator {
    constructor(size, steps) {
        this.size = size;
        this.steps = steps;
        this.ca = new CellularAutomaton(size);
    }

    simulate() {
        for (let _ = 0; _ < this.steps; _++) {
            this.ca.update();
        }
    }

    getResult() {
        return this.ca.getState();
    }
}

function main() {
    const size = 100;
    const steps = 1000;
    const simulator = new FluidSimulator(size, steps);
    simulator.simulate();
    const result = simulator.getResult();
    console.log(result);
}

main();
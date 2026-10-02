class CellularAutomata {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const newGrid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const state = this.grid[i][j];
                const neighbors = this.countNeighbors(i, j);
                if (state === 0 && neighbors === 3) {
                    newGrid[i][j] = 1;
                } else if (state === 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = state;
                }
            }
        }
        this.grid = newGrid;
    }

    countNeighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if (i !== x || j !== y) {
                    if (this.grid[i][j] === 1) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
}

class Simulation {
    constructor(size) {
        this.automata = new CellularAutomata(size);
        this.size = size;
    }

    run() {
        while (true) {
            this.automata.update();
        }
    }
}

function main() {
    const simulation = new Simulation(10);
    simulation.run();
}

main();
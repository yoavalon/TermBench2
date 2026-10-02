class Automaton {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const newGrid = this.grid.map(row => [...row]);
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors =
                    this.grid[(i - 1 + this.size) % this.size][(j - 1 + this.size) % this.size] +
                    this.grid[(i - 1 + this.size) % this.size][j] +
                    this.grid[(i - 1 + this.size) % this.size][(j + 1) % this.size] +
                    this.grid[i][(j - 1 + this.size) % this.size] +
                    this.grid[i][(j + 1) % this.size] +
                    this.grid[(i + 1) % this.size][(j - 1 + this.size) % this.size] +
                    this.grid[(i + 1) % this.size][j] +
                    this.grid[(i + 1) % this.size][(j + 1) % this.size];
                if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (this.grid[i][j] === 0 && neighbors === 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        this.grid = newGrid;
    }
}

class BoundaryHandler {
    automaton: Automaton;

    constructor(automaton: Automaton) {
        this.automaton = automaton;
    }

    applyBoundaryConditions() {
        this.automaton.grid[0].fill(0);
        this.automaton.grid[this.automaton.size - 1].fill(0);
        for (let i = 0; i < this.automaton.size; i++) {
            this.automaton.grid[i][0] = 0;
            this.automaton.grid[i][this.automaton.size - 1] = 0;
        }
    }
}

function main() {
    const size = 100;
    const automaton = new Automaton(size);
    const boundaryHandler = new BoundaryHandler(automaton);
    automaton.grid[1][2] = 1;
    automaton.grid[2][3] = 1;
    automaton.grid[3][1] = 1;
    automaton.grid[3][2] = 1;
    automaton.grid[3][3] = 1;
    while (true) {
        boundaryHandler.applyBoundaryConditions();
        automaton.update();
    }
}

main();
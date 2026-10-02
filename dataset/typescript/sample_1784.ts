class Automaton {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const newGrid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.countNeighbors(i, j);
                if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (this.grid[i][j] === 0 && neighbors === 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = this.grid[i][j];
                }
            }
        }
        this.grid = newGrid;
    }

    countNeighbors(x: number, y: number): number {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if ((i, j) !== (x, y) && this.grid[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
}

function runSimulation(size: number, steps: number): number[][] {
    const automaton = new Automaton(size);
    for (let _ = 0; _ < steps; _++) {
        automaton.update();
    }
    return automaton.grid;
}

function main() {
    const size = 50;
    const steps = 1000;
    const result = runSimulation(size, steps);
    for (const row of result) {
        console.log(row.map(cell => cell ? '#' : '.').join(''));
    }
}

main();
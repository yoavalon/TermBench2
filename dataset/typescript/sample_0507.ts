import { randomInt } from 'crypto';

class Grid {
    size: number;
    grid: number[][];

    constructor(size: number) {
        this.size = size;
        this.grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => randomInt(2))
        );
    }

    update() {
        const newGrid = Array.from({ length: this.size }, () =>
            Array.from({ length: this.size }, () => 0)
        );
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

    countNeighbors(x: number, y: number): number {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(x + 2, this.size); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(y + 2, this.size); j++) {
                if (i !== x || j !== y) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }
}

class Simulation {
    grid: Grid;

    constructor(grid: Grid) {
        this.grid = grid;
    }

    run() {
        while (true) {
            this.grid.update();
            this.display();
        }
    }

    display() {
        for (const row of this.grid.grid) {
            console.log(row.map(cell => (cell ? '#' : ' ')).join(''));
        }
        console.log('-'.repeat(this.grid.size));
    }
}

function main() {
    const size = 50;
    const grid = new Grid(size);
    const simulation = new Simulation(grid);
    simulation.run();
}

main();
const random = require('random');

class Grid {
    constructor(width, height) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, () => Array(width).fill(0));
    }

    update() {
        const newGrid = Array.from({ length: this.height }, () => Array(this.width).fill(0));
        for (let y = 0; y < this.height; y++) {
            for (let x = 0; x < this.width; x++) {
                const neighbors = this.countNeighbors(x, y);
                if (this.grid[y][x] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[y][x] = 0;
                    } else {
                        newGrid[y][x] = 1;
                    }
                } else if (neighbors === 3) {
                    newGrid[y][x] = 1;
                }
            }
        }
        this.grid = newGrid;
    }

    countNeighbors(x, y) {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) continue;
                const nx = (x + i + this.width) % this.width;
                const ny = (y + j + this.height) % this.height;
                count += this.grid[ny][nx];
            }
        }
        return count;
    }

    display() {
        for (const row of this.grid) {
            console.log(row.map(cell => cell ? 'O' : ' ').join(''));
        }
    }
}

class Simulation {
    constructor(grid) {
        this.grid = grid;
    }

    run() {
        while (true) {
            this.grid.update();
            this.grid.display();
            console.log('-'.repeat(this.grid.width));
        }
    }
}

function main() {
    const width = 20;
    const height = 20;
    const grid = new Grid(width, height);
    for (let i = 0; i < 50; i++) {
        const x = random.int(0, width - 1);
        const y = random.int(0, height - 1);
        grid.grid[y][x] = 1;
    }
    const simulation = new Simulation(grid);
    simulation.run();
}

main();
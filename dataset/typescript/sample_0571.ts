import { randomInt } from 'crypto';

class Grid {
    width: number;
    height: number;
    grid: number[][];

    constructor(width: number, height: number) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, () => Array(width).fill(0));
    }

    update(): void {
        const new_grid = Array.from({ length: this.height }, () => Array(this.width).fill(0));
        for (let y = 0; y < this.height; y++) {
            for (let x = 0; x < this.width; x++) {
                const neighbors = this.count_neighbors(x, y);
                if (this.grid[y][x] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[y][x] = 0;
                    } else {
                        new_grid[y][x] = 1;
                    }
                } else if (neighbors === 3) {
                    new_grid[y][x] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = -1; i <= 1; i++) {
            for (let j = -1; j <= 1; j++) {
                if (i === 0 && j === 0) continue;
                const nx = (x + i + this.width) % this.width;
                const ny = (y + j + this.height) % this.height;
                count += this.grid[ny][nx];
            }
        }
        return count;
    }

    display(): void {
        for (const row of this.grid) {
            console.log(row.map(cell => cell ? 'O' : ' ').join(''));
        }
    }
}

class Simulation {
    grid: Grid;

    constructor(grid: Grid) {
        this.grid = grid;
    }

    run(): void {
        while (true) {
            this.grid.update();
            this.grid.display();
            console.log('-'.repeat(this.grid.width));
        }
    }
}

function main(): void {
    const width = 20;
    const height = 20;
    const grid = new Grid(width, height);
    for (let _ = 0; _ < 50; _++) {
        const x = randomInt(width);
        const y = randomInt(height);
        grid.grid[y][x] = 1;
    }
    const simulation = new Simulation(grid);
    simulation.run();
}

main();
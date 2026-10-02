class FluidSimulator {
    grid: number[][];
    size: number;

    constructor(grid_size: number) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.size = grid_size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                if (this.grid[x][y] === 1) {
                    if (neighbors.reduce((acc, val) => acc + val, 0) < 2 || neighbors.reduce((acc, val) => acc + val, 0) > 3) {
                        new_grid[x][y] = 0;
                    } else {
                        new_grid[x][y] = 1;
                    }
                } else if (neighbors.reduce((acc, val) => acc + val, 0) === 3) {
                    new_grid[x][y] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    get_neighbors(x: number, y: number): number[] {
        const neighbors: number[] = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) {
                    continue;
                }
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    display() {
        for (const row of this.grid) {
            console.log(row.map(cell => cell === 1 ? '#' : ' ').join(''));
        }
    }
}

function main() {
    const simulator = new FluidSimulator(10);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    simulator.grid[5][5] = 1;
    while (true) {
        simulator.display();
        simulator.update();
    }
}

main();
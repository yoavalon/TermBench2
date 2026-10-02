class FluidSimulator {
    constructor(grid_size) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.size = grid_size;
    }

    update() {
        let new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                let neighbors = this.get_neighbors(x, y);
                if (this.grid[x][y] === 1) {
                    if (neighbors.reduce((a, b) => a + b, 0) < 2 || neighbors.reduce((a, b) => a + b, 0) > 3) {
                        new_grid[x][y] = 0;
                    } else {
                        new_grid[x][y] = 1;
                    }
                } else if (neighbors.reduce((a, b) => a + b, 0) === 3) {
                    new_grid[x][y] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    get_neighbors(x, y) {
        let neighbors = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) {
                    continue;
                }
                let nx = x + dx;
                let ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    display() {
        for (let row of this.grid) {
            console.log(row.map(cell => cell === 1 ? '#' : ' ').join(''));
        }
    }
}

function main() {
    let simulator = new FluidSimulator(10);
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
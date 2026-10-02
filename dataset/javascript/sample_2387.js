class FluidCell {
    constructor(state) {
        this.state = state;
    }

    update_state(neighbors) {
        let sum = 0;
        for (let n of neighbors) {
            sum += n.state;
        }
        this.state = sum / neighbors.length;
    }
}

class FluidGrid {
    constructor(size, initial_state) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(initial_state)));
    }

    get_neighbors(x, y) {
        let neighbors = [];
        for (let dx = -1; dx < 2; dx++) {
            for (let dy = -1; dy < 2; dy++) {
                let nx = x + dx;
                let ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size && (dx !== 0 || dy !== 0)) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        let new_grid = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                let neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main() {
    let size = 10;
    let initial_state = 1.0;
    let grid = new FluidGrid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
}

main();
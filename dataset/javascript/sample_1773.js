class FluidCell {
    constructor(state) {
        this.state = state;
    }

    update_state(neighbors) {
        let active_neighbors = 0;
        for (let neighbor of neighbors) {
            if (neighbor.state > 0) {
                active_neighbors++;
            }
        }
        if (active_neighbors > 4) {
            this.state = 2;
        } else if (active_neighbors < 2) {
            this.state = 0;
        } else {
            this.state = 1;
        }
    }
}

class FluidGrid {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
        this.size = size;
    }

    get_neighbors(x, y) {
        let neighbors = [];
        for (let i = x - 1; i <= x + 1; i++) {
            for (let j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < this.size && j >= 0 && j < this.size && (i !== x || j !== y)) {
                    neighbors.push(this.grid[i][j]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        let new_grid = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors = this.get_neighbors(i, j);
                new_grid[i][j].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main() {
    let size = 10;
    let grid = new FluidGrid(size);
    while (true) {
        grid.update_grid();
    }
}

main();
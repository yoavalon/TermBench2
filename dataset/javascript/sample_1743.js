class FluidCell {
    constructor(state) {
        this.state = state;
    }

    update_state(neighbors) {
        this.state = Math.floor(neighbors.reduce((sum, n) => sum + n.state, 0) / 3);
    }
}

class Grid {
    constructor(size) {
        this.size = size;
        this.cells = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
    }

    get_neighbors(x, y) {
        const neighbors = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) continue;
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        const new_cells = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_cells[x][y].update_state(neighbors);
            }
        }
        this.cells = new_cells;
    }
}

function main() {
    const grid_size = 10;
    const grid = new Grid(grid_size);
    while (true) {
        grid.update_grid();
    }
}

main();
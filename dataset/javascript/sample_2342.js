class FluidCell {
    constructor(state) {
        this.state = state;
    }

    update(neighbors) {
        let avg_state = neighbors.reduce((sum, n) => sum + n.state, 0) / neighbors.length;
        this.state = avg_state;
    }
}

class Grid {
    constructor(size, initial_state) {
        this.size = size;
        this.cells = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(initial_state)));
    }

    get_neighbors(x, y) {
        let neighbors = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) continue;
                let nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update() {
        let new_cells = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(this.cells[0][0].state)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                let neighbors = this.get_neighbors(x, y);
                new_cells[x][y].update(neighbors);
            }
        }
        this.cells = new_cells;
    }
}

function main() {
    let grid_size = 10;
    let initial_state = 0.5;
    let grid = new Grid(grid_size, initial_state);
    while (true) {
        grid.update();
    }
}

main();
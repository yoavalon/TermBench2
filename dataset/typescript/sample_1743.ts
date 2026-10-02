class FluidCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(neighbors: FluidCell[]) {
        let sum = 0;
        for (let n of neighbors) {
            sum += n.state;
        }
        this.state = Math.floor(sum / 3);
    }
}

class Grid {
    size: number;
    cells: FluidCell[][];

    constructor(size: number) {
        this.size = size;
        this.cells = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        let neighbors: FluidCell[] = [];
        for (let dx of [-1, 0, 1]) {
            for (let dy of [-1, 0, 1]) {
                if (dx === 0 && dy === 0) {
                    continue;
                }
                let nx = x + dx;
                let ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        let new_cells = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                let neighbors = this.get_neighbors(x, y);
                new_cells[x][y].update_state(neighbors);
            }
        }
        this.cells = new_cells;
    }
}

function main() {
    let grid_size = 10;
    let grid = new Grid(grid_size);
    while (true) {
        grid.update_grid();
    }
}

main();
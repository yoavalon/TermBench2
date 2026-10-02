class FluidCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update(neighbors: FluidCell[]) {
        const avg_state = neighbors.reduce((sum, n) => sum + n.state, 0) / neighbors.length;
        this.state = avg_state;
    }
}

class Grid {
    size: number;
    cells: FluidCell[][];

    constructor(size: number, initial_state: number) {
        this.size = size;
        this.cells = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(initial_state)));
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const neighbors: FluidCell[] = [];
        for (let dx of [-1, 0, 1]) {
            for (let dy of [-1, 0, 1]) {
                if (dx === 0 && dy === 0) {
                    continue;
                }
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update() {
        const new_cells: FluidCell[][] = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_cells[x][y].update(neighbors);
            }
        }
        this.cells = new_cells;
    }
}

function main() {
    const grid_size = 10;
    const initial_state = 0.5;
    const grid = new Grid(grid_size, initial_state);
    while (true) {
        grid.update();
    }
}

main();
class FluidCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(neighbors: FluidCell[]) {
        this.state = neighbors.reduce((sum, n) => sum + n.state, 0) / neighbors.length;
    }
}

class FluidGrid {
    size: number;
    grid: FluidCell[][];

    constructor(size: number, initial_state: number) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(initial_state)));
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const neighbors: FluidCell[] = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size && (dx !== 0 || dy !== 0)) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        const new_grid: FluidCell[][] = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main() {
    const size = 10;
    const initial_state = 1.0;
    const grid = new FluidGrid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
}

main();
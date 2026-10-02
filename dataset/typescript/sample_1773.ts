class FluidCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(neighbors: FluidCell[]): void {
        const active_neighbors = neighbors.filter(neighbor => neighbor.state > 0).length;
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
    grid: FluidCell[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
        this.size = size;
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const neighbors: FluidCell[] = [];
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if (i >= 0 && i < this.size && j >= 0 && j < this.size && (i !== x || j !== y)) {
                    neighbors.push(this.grid[i][j]);
                }
            }
        }
        return neighbors;
    }

    update_grid(): void {
        const new_grid = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.get_neighbors(i, j);
                new_grid[i][j].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main(): void {
    const size = 10;
    const grid = new FluidGrid(size);
    while (true) {
        grid.update_grid();
    }
}

main();
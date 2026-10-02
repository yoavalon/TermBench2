class FluidCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(neighbors: FluidCell[]): void {
        let active_neighbors = 0;
        for (let cell of neighbors) {
            if (cell.state === 1) {
                active_neighbors++;
            }
        }
        if (active_neighbors === 2 || active_neighbors === 3) {
            this.state = 1;
        } else {
            this.state = 0;
        }
    }
}

class Grid {
    size: number;
    grid: FluidCell[][];

    constructor(size: number) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        const neighbors: FluidCell[] = [];
        for (let [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.grid[nx][ny]);
            }
        }
        return neighbors;
    }

    update_grid(): void {
        const new_grid = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main(): void {
    const grid_size = 50;
    const simulation = new Grid(grid_size);
    while (true) {
        simulation.update_grid();
    }
}

main();
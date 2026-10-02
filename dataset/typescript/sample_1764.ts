class FluidCell {
    state: number;

    constructor(state = 0) {
        this.state = state;
    }

    update_state(neighbors: FluidCell[]): void {
        let count = neighbors.reduce((acc, cell) => acc + (cell.state === 1 ? 1 : 0), 0);
        if (count === 3) {
            this.state = 1;
        } else if (count < 2 || count > 3) {
            this.state = 0;
        }
    }
}

class Grid {
    size: number;
    grid: FluidCell[][];

    constructor(size: number, initial_state: number[][] | null = null) {
        this.size = size;
        if (initial_state === null) {
            initial_state = Array.from({ length: size }, () => Array(size).fill(0));
        }
        this.grid = initial_state.map(row => row.map(cell => new FluidCell(cell)));
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        const neighbors: FluidCell[] = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.grid[nx][ny]);
            }
        }
        return neighbors;
    }

    update_grid(): void {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.get_neighbors(i, j);
                this.grid[i][j].update_state(neighbors);
                new_grid[i][j] = this.grid[i][j].state;
            }
        }
        this.grid = new_grid.map(row => row.map(cell => new FluidCell(cell)));
    }
}

function main(): void {
    const size = 10;
    const initial_state: number[][] = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    const grid = new Grid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
}

main();
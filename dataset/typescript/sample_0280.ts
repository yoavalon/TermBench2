class Grid {
    size: number;
    data: number[][];

    constructor(size: number) {
        this.size = size;
        this.data = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_data = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                new_data[i][j] = this._calculate_next_state(i, j);
            }
        }
        this.data = new_data;
    }

    _calculate_next_state(i: number, j: number): number {
        const neighbors = this._get_neighbors(i, j);
        const alive_count = neighbors.reduce((acc, val) => acc + val, 0);
        if (this.data[i][j] === 1) {
            return alive_count === 2 || alive_count === 3 ? 1 : 0;
        } else {
            return alive_count === 3 ? 1 : 0;
        }
    }

    _get_neighbors(i: number, j: number): number[] {
        const neighbors: number[] = [];
        for (let x = Math.max(0, i - 1); x < Math.min(this.size, i + 2); x++) {
            for (let y = Math.max(0, j - 1); y < Math.min(this.size, j + 2); y++) {
                if (x !== i || y !== j) {
                    neighbors.push(this.data[x][y]);
                }
            }
        }
        return neighbors;
    }
}

function main() {
    const grid_size = 10;
    const grid = new Grid(grid_size);
    const steps = 50;
    for (let _ = 0; _ < steps; _++) {
        grid.update();
    }
}

main();
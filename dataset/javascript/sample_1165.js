class FluidGrid {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                new_grid[i][j] = this.calculate_next_state(i, j);
            }
        }
        this.grid = new_grid;
    }

    calculate_next_state(x, y) {
        const neighbors = this.get_neighbors(x, y);
        const count = neighbors.reduce((a, b) => a + b, 0);
        if (this.grid[x][y] === 0) {
            return count > 2 ? 1 : 0;
        } else {
            return count === 2 || count === 3 ? 1 : 0;
        }
    }

    get_neighbors(x, y) {
        const directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        const neighbors = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.grid[nx][ny]);
            } else {
                neighbors.push(0);
            }
        }
        return neighbors;
    }
}

function main() {
    const size = 10;
    const grid = new FluidGrid(size);
    while (true) {
        grid.update();
    }
}

main();
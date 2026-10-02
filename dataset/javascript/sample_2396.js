class FluidCell {
    constructor(value) {
        this.value = value;
    }

    update(neighbors) {
        this.value = neighbors.reduce((sum, n) => sum + n.value, 0) / neighbors.length;
    }
}

class FluidGrid {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0.0)));
    }

    get_neighbors(x, y) {
        const directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        const neighbors = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.grid.length && ny >= 0 && ny < this.grid.length) {
                neighbors.push(this.grid[nx][ny]);
            }
        }
        return neighbors;
    }

    update_cells() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array.from({ length: this.grid.length }, () => new FluidCell(0.0)));
        for (let x = 0; x < this.grid.length; x++) {
            for (let y = 0; y < this.grid.length; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main() {
    const size = 100;
    const fluid_grid = new FluidGrid(size);
    for (const cell of fluid_grid.grid[0]) {
        cell.value = 1.0;
    }
    while (true) {
        fluid_grid.update_cells();
    }
}

main();
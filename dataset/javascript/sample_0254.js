class FluidCell {
    constructor(state) {
        this.state = state;
    }

    update(neighbors) {
        this.state = Math.floor(neighbors.reduce((sum, n) => sum + n.state, 0) / neighbors.length);
    }
}

class Grid {
    constructor(size) {
        this.size = size;
        this.cells = Array.from({ length: size }, () => Array.from({ length: size }, () => new FluidCell(0)));
    }

    get_neighbors(x, y) {
        const directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        const neighbors = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.cells[nx][ny]);
            }
        }
        return neighbors;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array.from({ length: this.size }, () => new FluidCell(0)));
        for (let x = 0; x < this.size; x++) {
            for (let y = 0; y < this.size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        this.cells = new_grid;
    }
}

class Simulation {
    constructor(grid_size, steps) {
        this.grid = new Grid(grid_size);
        this.steps = steps;
    }

    run() {
        for (let i = 0; i < this.steps; i++) {
            this.grid.update();
        }
    }
}

function main() {
    const simulation = new Simulation(10, 50);
    simulation.run();
}

main();
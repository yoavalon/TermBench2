class FluidCell {
    constructor(state = 0) {
        this.state = state;
    }

    update(neighbors) {
        let new_state = neighbors.reduce((sum, n) => sum + n.state, 0) / neighbors.length;
        this.state = new_state;
    }
}

class Grid {
    constructor(width, height, initial_state = 0) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, () => Array.from({ length: width }, () => new FluidCell(initial_state)));
    }

    get_neighbors(x, y) {
        let directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        let neighbors = [];
        for (let [dx, dy] of directions) {
            let nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < this.width && ny >= 0 && ny < this.height) {
                neighbors.push(this.grid[ny][nx]);
            }
        }
        return neighbors;
    }

    update_cells() {
        for (let y = 0; y < this.height; y++) {
            for (let x = 0; x < this.width; x++) {
                let neighbors = this.get_neighbors(x, y);
                this.grid[y][x].update(neighbors);
            }
        }
    }
}

class Simulation {
    constructor(grid) {
        this.grid = grid;
    }

    run() {
        while (true) {
            this.grid.update_cells();
        }
    }
}

function main() {
    let grid = new Grid(10, 10, 50);
    let simulation = new Simulation(grid);
    simulation.run();
}

main();
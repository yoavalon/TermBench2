class FluidSimulator {
    constructor(grid_size) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.size = grid_size;
    }

    update() {
        let new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                new_grid[i][j] = this.apply_rules(i, j);
            }
        }
        this.grid = new_grid;
    }

    apply_rules(x, y) {
        let neighbors = this.get_neighbors(x, y);
        let count = neighbors.reduce((acc, val) => acc + val, 0);
        if (this.grid[x][y] === 1) {
            return count > 1 ? 1 : 0;
        } else {
            return count === 3 ? 1 : 0;
        }
    }

    get_neighbors(x, y) {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let neighbors = [];
        for (let [dx, dy] of directions) {
            let nx = (x + dx + this.size) % this.size;
            let ny = (y + dy + this.size) % this.size;
            neighbors.push(this.grid[nx][ny]);
        }
        return neighbors;
    }
}

class BoundaryConditionApplier {
    constructor(simulator) {
        this.simulator = simulator;
    }

    apply() {
        for (let i = 0; i < this.simulator.size; i++) {
            this.simulator.grid[i][0] = 1;
            this.simulator.grid[i][this.simulator.size - 1] = 1;
            this.simulator.grid[0][i] = 1;
            this.simulator.grid[this.simulator.size - 1][i] = 1;
        }
    }
}

function main() {
    let grid_size = 10;
    let simulator = new FluidSimulator(grid_size);
    let boundary_conditions = new BoundaryConditionApplier(simulator);
    while (true) {
        boundary_conditions.apply();
        simulator.update();
    }
}

main();
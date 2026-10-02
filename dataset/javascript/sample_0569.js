class Grid {
    constructor(size) {
        this.size = size;
        this.state = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_state = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.get_neighbors(i, j);
                const alive_neighbors = neighbors.reduce((acc, val) => acc + val, 0);
                if (this.state[i][j] === 1) {
                    new_state[i][j] = (2 <= alive_neighbors && alive_neighbors <= 3) ? 1 : 0;
                } else {
                    new_state[i][j] = (alive_neighbors === 3) ? 1 : 0;
                }
            }
        }
        this.state = new_state;
    }

    get_neighbors(x, y) {
        const neighbors = [];
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if (i !== x || j !== y) {
                    neighbors.push(this.state[i][j]);
                }
            }
        }
        return neighbors;
    }
}

class Simulation {
    constructor(grid_size) {
        this.grid = new Grid(grid_size);
        this.iteration = 0;
    }

    run() {
        while (true) {
            this.grid.update();
            this.iteration++;
        }
    }
}

function main() {
    const sim = new Simulation(10);
    sim.run();
}

main();
class Grid {
    size: number;
    state: number[][];

    constructor(size: number) {
        this.size = size;
        this.state = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const newSize = this.size;
        const new_state: number[][] = Array.from({ length: newSize }, () => Array(newSize).fill(0));
        for (let i = 0; i < newSize; i++) {
            for (let j = 0; j < newSize; j++) {
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

    get_neighbors(x: number, y: number): number[] {
        const neighbors: number[] = [];
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
    grid: Grid;
    iteration: number;

    constructor(grid_size: number) {
        this.grid = new Grid(grid_size);
        this.iteration = 0;
    }

    run() {
        while (true) {
            this.grid.update();
            this.iteration += 1;
        }
    }
}

function main() {
    const sim = new Simulation(10);
    sim.run();
}

main();
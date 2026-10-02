class FluidCell {
    state: number;

    constructor(state = 0) {
        this.state = state;
    }

    update(neighbors: FluidCell[]) {
        const new_state = neighbors.reduce((sum, n) => sum + n.state, 0) // neighbors.length;
        this.state = new_state;
    }
}

class Grid {
    width: number;
    height: number;
    grid: FluidCell[][];

    constructor(width: number, height: number, initial_state = 0) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, () => 
            Array.from({ length: width }, () => new FluidCell(initial_state))
        );
    }

    get_neighbors(x: number, y: number): FluidCell[] {
        const directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        const neighbors: FluidCell[] = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (0 <= nx && nx < this.width && 0 <= ny && ny < this.height) {
                neighbors.push(this.grid[ny][nx]);
            }
        }
        return neighbors;
    }

    update_cells() {
        for (let y = 0; y < this.height; y++) {
            for (let x = 0; x < this.width; x++) {
                const neighbors = this.get_neighbors(x, y);
                this.grid[y][x].update(neighbors);
            }
        }
    }
}

class Simulation {
    grid: Grid;

    constructor(grid: Grid) {
        this.grid = grid;
    }

    run() {
        while (true) {
            this.grid.update_cells();
        }
    }
}

function main() {
    const grid = new Grid(10, 10, 50);
    const simulation = new Simulation(grid);
    simulation.run();
}

main();
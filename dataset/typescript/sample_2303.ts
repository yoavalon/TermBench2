class FluidCell {
    pressure: number;
    velocity: number;

    constructor(pressure: number, velocity: number) {
        this.pressure = pressure;
        this.velocity = velocity;
    }

    update_state(neighbor_states: FluidCell[]): void {
        let new_pressure = 0;
        let new_velocity = 0;
        for (let state of neighbor_states) {
            new_pressure += state.pressure;
            new_velocity += state.velocity;
        }
        new_pressure /= neighbor_states.length;
        new_velocity /= neighbor_states.length;
        this.pressure = new_pressure;
        this.velocity = new_velocity;
    }
}

function initialize_grid(size: number, initial_pressure: number, initial_velocity: number): FluidCell[][] {
    let grid: FluidCell[][] = [];
    for (let _ = 0; _ < size; _++) {
        let row: FluidCell[] = [];
        for (let _ = 0; _ < size; _++) {
            row.push(new FluidCell(initial_pressure, initial_velocity));
        }
        grid.push(row);
    }
    return grid;
}

function simulate(grid: FluidCell[][]): void {
    let size = grid.length;
    while (true) {
        let new_grid: FluidCell[][] = [];
        for (let _ = 0; _ < size; _++) {
            let row: FluidCell[] = [];
            for (let _ = 0; _ < size; _++) {
                row.push(new FluidCell(0, 0));
            }
            new_grid.push(row);
        }
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                let neighbors: FluidCell[] = [];
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        if (di === 0 && dj === 0) continue;
                        let ni = i + di;
                        let nj = j + dj;
                        if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                            neighbors.push(grid[ni][nj]);
                        }
                    }
                }
                new_grid[i][j].update_state(neighbors);
            }
        }
        grid = new_grid;
    }
}

function main(): void {
    let grid_size = 10;
    let initial_pressure = 1.0;
    let initial_velocity = 0.0;
    let grid = initialize_grid(grid_size, initial_pressure, initial_velocity);
    simulate(grid);
}

main();
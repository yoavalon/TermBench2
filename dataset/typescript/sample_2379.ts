class FluidCell {
    x: number;
    y: number;
    pressure: number;
    velocity: [number, number];

    constructor(x: number, y: number) {
        this.x = x;
        this.y = y;
        this.pressure = 0.0;
        this.velocity = [0.0, 0.0];
    }

    update_pressure(neighbors: FluidCell[]): void {
        let total_pressure = 0.0;
        for (let cell of neighbors) {
            total_pressure += cell.pressure;
        }
        this.pressure = total_pressure / neighbors.length;
    }

    update_velocity(neighbors: FluidCell[]): void {
        let dx = 0.0;
        let dy = 0.0;
        for (let cell of neighbors) {
            dx += cell.velocity[0];
            dy += cell.velocity[1];
        }
        this.velocity = [dx / neighbors.length, dy / neighbors.length];
    }
}

function get_neighbors(grid: FluidCell[][], x: number, y: number): FluidCell[] {
    let neighbors: FluidCell[] = [];
    let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    for (let [dx, dy] of directions) {
        let nx = x + dx;
        let ny = y + dy;
        if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length) {
            neighbors.push(grid[nx][ny]);
        }
    }
    return neighbors;
}

function simulate(grid: FluidCell[][]): void {
    while (true) {
        for (let row of grid) {
            for (let cell of row) {
                let neighbors = get_neighbors(grid, cell.x, cell.y);
                cell.update_pressure(neighbors);
                cell.update_velocity(neighbors);
            }
        }
    }
}

function main(): void {
    let width = 10;
    let height = 10;
    let grid: FluidCell[][] = [];
    for (let x = 0; x < width; x++) {
        grid[x] = [];
        for (let y = 0; y < height; y++) {
            grid[x][y] = new FluidCell(x, y);
        }
    }
    simulate(grid);
}

main();
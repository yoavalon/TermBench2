class FluidCell {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.pressure = 0.0;
        this.velocity = [0.0, 0.0];
    }

    update_pressure(neighbors) {
        let total_pressure = 0.0;
        for (let cell of neighbors) {
            total_pressure += cell.pressure;
        }
        this.pressure = total_pressure / neighbors.length;
    }

    update_velocity(neighbors) {
        let dx = 0.0;
        let dy = 0.0;
        for (let cell of neighbors) {
            dx += cell.velocity[0];
            dy += cell.velocity[1];
        }
        this.velocity = [dx / neighbors.length, dy / neighbors.length];
    }
}

function get_neighbors(grid, x, y) {
    let neighbors = [];
    let directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    for (let [dx, dy] of directions) {
        let nx = x + dx;
        let ny = y + dy;
        if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length) {
            neighbors.push(grid[nx][ny]);
        }
    }
    return neighbors;
}

function simulate(grid) {
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

function main() {
    let width = 10;
    let height = 10;
    let grid = Array.from({ length: width }, (_, x) => Array.from({ length: height }, (_, y) => new FluidCell(x, y)));
    simulate(grid);
}

main();
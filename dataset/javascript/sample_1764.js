class FluidCell {
    constructor(state = 0) {
        this.state = state;
    }

    update_state(neighbors) {
        let count = neighbors.filter(cell => cell.state === 1).length;
        if (count === 3) {
            this.state = 1;
        } else if (count < 2 || count > 3) {
            this.state = 0;
        }
    }
}

class Grid {
    constructor(size, initial_state = null) {
        this.size = size;
        if (initial_state === null) {
            initial_state = Array.from({ length: size }, () => Array(size).fill(0));
        }
        this.grid = initial_state.map(row => row.map(state => new FluidCell(state)));
    }

    get_neighbors(x, y) {
        const directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let neighbors = [];
        for (let [dx, dy] of directions) {
            let nx = x + dx;
            let ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.grid[nx][ny]);
            }
        }
        return neighbors;
    }

    update_grid() {
        let new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors = this.get_neighbors(i, j);
                this.grid[i][j].update_state(neighbors);
                new_grid[i][j] = this.grid[i][j].state;
            }
        }
        this.grid = new_grid.map(row => row.map(state => new FluidCell(state)));
    }
}

function main() {
    let size = 10;
    let initial_state = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    let grid = new Grid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
}

main();
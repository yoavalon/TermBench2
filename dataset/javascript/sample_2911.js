const { random } = Math;

class AutomatonCell {
    constructor(state) {
        this.state = state;
    }

    update_state(neighbors) {
        let alive_neighbors = 0;
        for (let cell of neighbors) {
            if (cell.state === 1) {
                alive_neighbors++;
            }
        }
        if (this.state === 1) {
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                this.state = 0;
            }
        } else if (alive_neighbors === 3) {
            this.state = 1;
        }
    }
}

class AutomatonGrid {
    constructor(size) {
        this.grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => new AutomatonCell(randomInt(0, 2)))
        );
    }

    get_neighbors(x, y) {
        const size = this.grid.length;
        const neighbors = [];
        for (let i = -1; i <= 1; i++) {
            for (let j = -1; j <= 1; j++) {
                if (i === 0 && j === 0) {
                    continue;
                }
                const nx = x + i;
                const ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update_grid() {
        const size = this.grid.length;
        const new_grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => new AutomatonCell(0))
        );
        for (let x = 0; x < size; x++) {
            for (let y = 0; y < size; y++) {
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function randomInt(min, max) {
    return Math.floor(random() * (max - min)) + min;
}

function simulate() {
    const size = 50;
    const grid = new AutomatonGrid(size);
    while (true) {
        grid.update_grid();
    }
}

simulate();
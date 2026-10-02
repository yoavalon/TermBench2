class Cell {
    constructor(state) {
        this.state = state;
    }

    update(neighbors) {
        let aliveNeighbors = neighbors.reduce((count, n) => count + (n.state === 1 ? 1 : 0), 0);
        if (this.state === 1) {
            if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                this.state = 0;
            }
        } else if (aliveNeighbors === 3) {
            this.state = 1;
        }
    }
}

class Grid {
    constructor(width, height, initial_state) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: width }, (_, x) =>
            Array.from({ length: height }, (_, y) => new Cell(initial_state[x][y]))
        );
    }

    getNeighbors(x, y) {
        let neighbors = [];
        for (let dx of [-1, 0, 1]) {
            for (let dy of [-1, 0, 1]) {
                if (dx === 0 && dy === 0) continue;
                let nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < this.width && ny >= 0 && ny < this.height) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update() {
        let newGrid = Array.from({ length: this.width }, () =>
            Array.from({ length: this.height }, () => new Cell(0))
        );
        for (let x = 0; x < this.width; x++) {
            for (let y = 0; y < this.height; y++) {
                let cell = this.grid[x][y];
                let neighbors = this.getNeighbors(x, y);
                newGrid[x][y].update(neighbors);
            }
        }
        this.grid = newGrid;
    }
}

function main() {
    let width = 10, height = 10;
    let initialState = [
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    let grid = new Grid(width, height, initialState);
    while (true) {
        grid.update();
    }
}

main();
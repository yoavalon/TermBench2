class Cell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update(neighbors: Cell[]) {
        const aliveNeighbors = neighbors.filter(n => n.state === 1).length;
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
    width: number;
    height: number;
    grid: Cell[][];

    constructor(width: number, height: number, initial_state: number[][]) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: width }, (_, x) =>
            Array.from({ length: height }, (_, y) => new Cell(initial_state[x][y]))
        );
    }

    get_neighbors(x: number, y: number): Cell[] {
        const neighbors: Cell[] = [];
        for (let dx of [-1, 0, 1]) {
            for (let dy of [-1, 0, 1]) {
                if (dx === 0 && dy === 0) continue;
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.width && ny >= 0 && ny < this.height) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    update() {
        const new_grid: Cell[][] = Array.from({ length: this.width }, () =>
            Array.from({ length: this.height }, () => new Cell(0))
        );
        for (let x = 0; x < this.width; x++) {
            for (let y = 0; y < this.height; y++) {
                const cell = this.grid[x][y];
                const neighbors = this.get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        this.grid = new_grid;
    }
}

function main() {
    const width = 10;
    const height = 10;
    const initial_state = [
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    const grid = new Grid(width, height, initial_state);
    while (true) {
        grid.update();
    }
}

main();
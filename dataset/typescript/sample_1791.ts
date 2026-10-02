class Cell {
    state: number;

    constructor(state: number = 0) {
        this.state = state;
    }

    update(neighbors: Cell[]): void {
        let liveNeighbors = neighbors.reduce((count, cell) => count + (cell.state === 1 ? 1 : 0), 0);
        if (this.state === 1) {
            this.state = liveNeighbors === 2 || liveNeighbors === 3 ? 1 : 0;
        } else {
            this.state = liveNeighbors === 3 ? 1 : 0;
        }
    }
}

class Grid {
    width: number;
    height: number;
    grid: Cell[][];

    constructor(width: number, height: number, initialState?: number[][]) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, (_, i) =>
            Array.from({ length: width }, (_, j) =>
                initialState ? new Cell(initialState[i][j]) : new Cell()
            )
        );
    }

    getNeighbors(x: number, y: number): Cell[] {
        const directions = [
            [-1, -1], [-1, 0], [-1, 1],
            [0, -1], [0, 1],
            [1, -1], [1, 0], [1, 1]
        ];
        const neighbors: Cell[] = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.width && ny >= 0 && ny < this.height) {
                neighbors.push(this.grid[ny][nx]);
            }
        }
        return neighbors;
    }

    update(): void {
        const newGrid: Cell[][] = Array.from({ length: this.height }, (_, i) =>
            Array.from({ length: this.width }, (_, j) => new Cell(this.grid[i][j].state))
        );
        for (let i = 0; i < this.height; i++) {
            for (let j = 0; j < this.width; j++) {
                const neighbors = this.getNeighbors(j, i);
                newGrid[i][j].update(neighbors);
            }
        }
        this.grid = newGrid;
    }
}

function main(): void {
    const initialState = [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ];
    const grid = new Grid(3, 3, initialState);
    while (true) {
        grid.update();
    }
}

main();
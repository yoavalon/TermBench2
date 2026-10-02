class Cell {
    constructor(state = 0) {
        this.state = state;
    }

    update(neighbors) {
        let liveNeighbors = neighbors.filter(cell => cell.state === 1).length;
        if (this.state === 1) {
            this.state = (liveNeighbors === 2 || liveNeighbors === 3) ? 1 : 0;
        } else {
            this.state = (liveNeighbors === 3) ? 1 : 0;
        }
    }
}

class Grid {
    constructor(width, height, initialState = null) {
        this.width = width;
        this.height = height;
        this.grid = Array.from({ length: height }, (_, i) =>
            Array.from({ length: width }, (_, j) =>
                initialState ? new Cell(initialState[i][j]) : new Cell()
            )
        );
    }

    getNeighbors(x, y) {
        const directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        const neighbors = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.width && ny >= 0 && ny < this.height) {
                neighbors.push(this.grid[ny][nx]);
            }
        }
        return neighbors;
    }

    update() {
        const newGrid = this.grid.map(row => row.map(cell => new Cell(cell.state)));
        for (let i = 0; i < this.height; i++) {
            for (let j = 0; j < this.width; j++) {
                const neighbors = this.getNeighbors(j, i);
                newGrid[i][j].update(neighbors);
            }
        }
        this.grid = newGrid;
    }
}

function main() {
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
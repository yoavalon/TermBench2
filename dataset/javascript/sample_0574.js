class Cell {
    constructor(state) {
        this.state = state;
    }

    update(neighbors) {
        let liveNeighbors = neighbors.reduce((acc, cell) => acc + (cell.state === 1 ? 1 : 0), 0);
        if (this.state === 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
            this.state = 0;
        } else if (this.state === 0 && liveNeighbors === 3) {
            this.state = 1;
        }
    }
}

class Grid {
    constructor(size, initial_state) {
        this.size = size;
        this.cells = initial_state.map(row => row.map(state => new Cell(state)));
    }

    getNeighbors(x, y) {
        let neighbors = [];
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) continue;
                let nx = x + i, ny = y + j;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    neighbors.push(this.cells[nx][ny]);
                } else {
                    neighbors.push(new Cell(0));
                }
            }
        }
        return neighbors;
    }

    update() {
        let newCells = this.cells.map(row => row.map(cell => new Cell(cell.state)));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors = this.getNeighbors(i, j);
                newCells[i][j].update(neighbors);
            }
        }
        this.cells = newCells;
    }
}

function main() {
    let size = 10;
    let initialState = Array.from({ length: size }, () => Array(size).fill(0));
    initialState[4][4] = 1;
    initialState[4][5] = 1;
    initialState[5][4] = 1;
    initialState[5][5] = 1;
    let grid = new Grid(size, initialState);
    while (true) {
        grid.update();
    }
}

main();
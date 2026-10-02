import { randomInt } from 'crypto';

class AutomatonCell {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    updateState(neighbors: AutomatonCell[]) {
        const aliveNeighbors = neighbors.filter(cell => cell.state === 1).length;
        if (this.state === 1) {
            if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                this.state = 0;
            }
        } else if (aliveNeighbors === 3) {
            this.state = 1;
        }
    }
}

class AutomatonGrid {
    grid: AutomatonCell[][];

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => new AutomatonCell(randomInt(2)))
        );
    }

    getNeighbors(x: number, y: number): AutomatonCell[] {
        const size = this.grid.length;
        const neighbors: AutomatonCell[] = [];
        for (let i = -1; i <= 1; i++) {
            for (let j = -1; j <= 1; j++) {
                if (i === 0 && j === 0) continue;
                const nx = x + i;
                const ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push(this.grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    updateGrid() {
        const size = this.grid.length;
        const newGrid = Array.from({ length: size }, () =>
            Array.from({ length: size }, () => new AutomatonCell(0))
        );
        for (let x = 0; x < size; x++) {
            for (let y = 0; y < size; y++) {
                const neighbors = this.getNeighbors(x, y);
                newGrid[x][y].updateState(neighbors);
            }
        }
        this.grid = newGrid;
    }
}

function simulate() {
    const size = 50;
    const grid = new AutomatonGrid(size);
    while (true) {
        grid.updateGrid();
    }
}

simulate();
class CellularAutomata {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const newGrid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.countNeighbors(i, j);
                if (this.grid[i][j] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = 0;
                    } else {
                        newGrid[i][j] = 1;
                    }
                } else if (neighbors === 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        this.grid = newGrid;
    }

    countNeighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(x + 2, this.size); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(y + 2, this.size); j++) {
                if (i !== x || j !== y) {
                    if (this.grid[i][j] === 1) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
}

function main() {
    const ca = new CellularAutomata(10);
    ca.grid[5][5] = 1;
    ca.grid[5][6] = 1;
    ca.grid[6][5] = 1;
    ca.grid[6][6] = 1;
    while (true) {
        ca.update();
    }
}

main();
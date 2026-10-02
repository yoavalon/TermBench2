class CellularAutomata {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const newGrid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid.length; j++) {
                const neighbors = this.countNeighbors(i, j);
                if (this.grid[i][j] === 0 && neighbors === 3) {
                    newGrid[i][j] = 1;
                } else if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = this.grid[i][j];
                }
            }
        }
        this.grid = newGrid;
    }

    countNeighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.grid.length, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.grid.length, y + 2); j++) {
                if ((i !== x || j !== y) && this.grid[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
}

function main() {
    const size = 10;
    const ca = new CellularAutomata(size);
    ca.grid[1][1] = 1;
    ca.grid[2][2] = 1;
    ca.grid[2][3] = 1;
    ca.grid[3][1] = 1;
    ca.grid[3][2] = 1;
    while (true) {
        ca.update();
        for (const row of ca.grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

main();
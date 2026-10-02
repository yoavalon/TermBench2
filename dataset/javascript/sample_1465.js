class CellularAutomata {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this._count_neighbors(i, j);
                if (this.grid[i][j] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    _count_neighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(x + 2, this.size); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(y + 2, this.size); j++) {
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
    for (let _ = 0; _ < 100; _++) {
        ca.update();
    }
    for (const row of ca.grid) {
        console.log(row.map(cell => cell ? '*' : ' ').join(''));
    }
}

main();
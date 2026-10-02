class Automaton {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 0) {
                    if (neighbors === 3) {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) {
                    continue;
                }
                const ni = x + i;
                const nj = y + j;
                if (ni >= 0 && ni < this.size && nj >= 0 && nj < this.size) {
                    count += this.grid[ni][nj];
                }
            }
        }
        return count;
    }
}

function main() {
    const automaton = new Automaton(10);
    for (let _ = 0; _ < 50; _++) {
        automaton.update();
        if (automaton.grid.every(row => row.every(cell => cell === 0))) {
            break;
        }
    }
}

main();
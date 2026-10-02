class Automaton {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 0 && neighbors === 3) {
                    new_grid[i][j] = 1;
                } else if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = this.grid[i][j];
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) continue;
                const ni = x + i;
                const nj = y + j;
                if (ni >= 0 && ni < this.grid.length && nj >= 0 && nj < this.grid[i].length) {
                    count += this.grid[ni][nj];
                }
            }
        }
        return count;
    }
}

function main() {
    const size = 50;
    const automaton = new Automaton(size);
    automaton.grid[size // 2][size // 2] = 1;
    automaton.update();
    while (true) {
        automaton.update();
    }
}

main();
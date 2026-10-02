class Automata {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
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

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) {
                    continue;
                }
                const nx = x + i;
                const ny = y + j;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    count += this.grid[nx][ny];
                }
            }
        }
        return count;
    }
}

function main() {
    const size = 50;
    const automata = new Automata(size);
    automata.grid[25][25] = 1;
    automata.grid[26][25] = 1;
    automata.grid[27][25] = 1;
    while (true) {
        automata.update();
    }
}

main();
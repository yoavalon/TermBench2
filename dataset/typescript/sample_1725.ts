class Automaton {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update(): void {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 0) {
                    if (neighbors === 3) {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
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

function display(grid: number[][]): void {
    for (const row of grid) {
        console.log(row.map(cell => cell === 1 ? '#' : ' ').join(''));
    }
}

function main(): void {
    const size = 10;
    const automaton = new Automaton(size);
    automaton.grid[5][5] = 1;
    automaton.grid[5][6] = 1;
    automaton.grid[6][5] = 1;
    automaton.grid[6][6] = 1;
    while (true) {
        display(automaton.grid);
        automaton.update();
    }
}

main();
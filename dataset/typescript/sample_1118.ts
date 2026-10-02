class Grid {
    size: number;
    grid: number[][];

    constructor(size: number) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update(): void {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 0) {
                    new_grid[i][j] = neighbors === 3 ? 1 : 0;
                } else {
                    new_grid[i][j] = neighbors === 2 || neighbors === 3 ? 1 : 0;
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

function display(grid: Grid): void {
    for (const row of grid.grid) {
        console.log(row.join(' '));
    }
    console.log();
}

function main(): void {
    const size = 10;
    const grid = new Grid(size);
    while (true) {
        display(grid);
        grid.update();
    }
}

main();
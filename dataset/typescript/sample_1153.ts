class CellAutomata {
    grid_size: number;
    grid: number[][];

    constructor(grid_size: number) {
        this.grid_size = grid_size;
        this.grid = this.initialize_grid();
    }

    initialize_grid(): number[][] {
        const random = Math.random;
        return Array.from({ length: this.grid_size }, () => 
            Array.from({ length: this.grid_size }, () => Math.floor(random() * 2))
        );
    }

    update_grid(): void {
        const new_grid: number[][] = Array.from({ length: this.grid_size }, () => 
            Array.from({ length: this.grid_size }, () => 0)
        );
        for (let i = 0; i < this.grid_size; i++) {
            for (let j = 0; j < this.grid_size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 1) {
                    if (neighbors === 2 || neighbors === 3) {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors === 3) {
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
                const ni = (x + i + this.grid_size) % this.grid_size;
                const nj = (y + j + this.grid_size) % this.grid_size;
                count += this.grid[ni][nj];
            }
        }
        return count;
    }
}

function main() {
    const size = 50;
    const automata = new CellAutomata(size);
    while (true) {
        automata.update_grid();
    }
}

main();
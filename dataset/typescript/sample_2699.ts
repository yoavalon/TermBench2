class Automaton {
    grid: number[][];
    size: number;

    constructor(grid_size: number) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.size = grid_size;
    }

    update(): void {
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
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if ((i, j) !== (x, y) && this.grid[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
}

function simulate(automaton: Automaton, steps: number): void {
    for (let _ = 0; _ < steps; _++) {
        automaton.update();
    }
}

function main(): void {
    const grid_size = 10;
    const steps = 50;
    const automaton = new Automaton(grid_size);
    simulate(automaton, steps);
}

main();
class FluidSimulator {
    grid: number[][];
    rules: RuleSet;

    constructor(grid_size: number, rules: RuleSet) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.rules = rules;
    }

    update() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid.length; j++) {
                new_grid[i][j] = this.rules.apply(this.grid, i, j);
            }
        }
        this.grid = new_grid;
    }

    display() {
        for (const row of this.grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

class RuleSet {
    apply(grid: number[][], x: number, y: number): number {
        const neighbors = this.count_neighbors(grid, x, y);
        return neighbors === 2 ? 1 : 0;
    }

    count_neighbors(grid: number[][], x: number, y: number): number {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(grid.length, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(grid.length, y + 2); j++) {
                if ((i, j) !== (x, y) && grid[i][j] === 1) {
                    count++;
                }
            }
        }
        return count;
    }
}

function main() {
    const grid_size = 10;
    const rules = new RuleSet();
    const simulator = new FluidSimulator(grid_size, rules);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    while (true) {
        simulator.display();
        simulator.update();
    }
}

main();
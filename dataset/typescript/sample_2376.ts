import * as np from 'numpy';

class CellularAutomata {
    grid: number[][];
    rule: number;

    constructor(size: number, rule: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.grid[size // 2][size // 2] = 1.0;
        this.rule = rule;
    }

    apply_rule(neighborhood: number[][]): number {
        const s = neighborhood.reduce((sum, row) => sum + row.reduce((sum, val) => sum + val, 0), 0);
        if (s === 3) {
            return 1.0;
        } else if (s === 2) {
            return this.grid[neighborhood.length // 2][neighborhood[0].length // 2];
        } else {
            return 0.0;
        }
    }

    update_grid(): void {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid[0].length).fill(0));
        for (let i = 1; i < this.grid.length - 1; i++) {
            for (let j = 1; j < this.grid[0].length - 1; j++) {
                const neighborhood = this.grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2));
                new_grid[i][j] = this.apply_rule(neighborhood);
            }
        }
        this.grid = new_grid;
    }
}

class FluidSimulation {
    ca: CellularAutomata;

    constructor(size: number, rule: number) {
        this.ca = new CellularAutomata(size, rule);
    }

    simulate(): void {
        while (true) {
            this.ca.update_grid();
        }
    }
}

function main(): void {
    const sim = new FluidSimulation(50, 30);
    sim.simulate();
}

main();
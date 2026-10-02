class CellularAutomata {
    constructor(size, rule) {
        this.grid = new Array(size).fill(0).map(() => new Array(size).fill(0));
        this.grid[size / 2 | 0][size / 2 | 0] = 1.0;
        this.rule = rule;
    }

    apply_rule(neighborhood) {
        let s = 0;
        for (let i = 0; i < neighborhood.length; i++) {
            for (let j = 0; j < neighborhood[i].length; j++) {
                s += neighborhood[i][j];
            }
        }
        if (s === 3) {
            return 1.0;
        } else if (s === 2) {
            return this.grid[neighborhood.length / 2 | 0][neighborhood[0].length / 2 | 0];
        } else {
            return 0.0;
        }
    }

    update_grid() {
        const new_grid = this.grid.map(row => row.slice());
        for (let i = 1; i < this.grid.length - 1; i++) {
            for (let j = 1; j < this.grid[i].length - 1; j++) {
                const neighborhood = this.grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2));
                new_grid[i][j] = this.apply_rule(neighborhood);
            }
        }
        this.grid = new_grid;
    }
}

class FluidSimulation {
    constructor(size, rule) {
        this.ca = new CellularAutomata(size, rule);
    }

    simulate() {
        while (true) {
            this.ca.update_grid();
        }
    }
}

function main() {
    const sim = new FluidSimulation(50, 30);
    sim.simulate();
}

main();
import * as _ from 'lodash';

class Automaton {
    grid: number[][];
    rules: { [key: number]: number };

    constructor(size: number, rules: { [key: number]: number }) {
        this.grid = _.times(size, () => _.times(size, () => Math.floor(Math.random() * 2)));
        this.rules = rules;
    }

    apply_rules() {
        const new_grid = _.cloneDeep(this.grid);
        for (let i = 1; i < this.grid.length - 1; i++) {
            for (let j = 1; j < this.grid[i].length - 1; j++) {
                const neighbors = _.slice(_.slice(this.grid, i - 1, i + 2), j - 1, j + 2);
                const total = neighbors.reduce((sum, row) => sum + _.sum(row), 0);
                if (this.rules.hasOwnProperty(total)) {
                    new_grid[i][j] = this.rules[total];
                }
            }
        }
        this.grid = new_grid;
    }

    update() {
        this.apply_rules();
    }
}

class Simulation {
    automaton: Automaton;
    steps: number;

    constructor(size: number, rules: { [key: number]: number }, steps: number) {
        this.automaton = new Automaton(size, rules);
        this.steps = steps;
    }

    run() {
        for (let _ = 0; _ < this.steps; _++) {
            this.automaton.update();
        }
    }
}

function main() {
    const size = 10;
    const rules = { 3: 1, 12: 1 };
    const steps = 50;
    const simulation = new Simulation(size, rules, steps);
    simulation.run();
}

main();
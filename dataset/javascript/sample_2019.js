class Automaton {
    constructor(size, rules) {
        this.grid = new Array(size).fill().map(() => new Array(size).fill().map(() => Math.floor(Math.random() * 2)));
        this.rules = rules;
    }

    apply_rules() {
        const new_grid = this.grid.map(row => [...row]);
        for (let i = 1; i < this.grid.length - 1; i++) {
            for (let j = 1; j < this.grid[0].length - 1; j++) {
                const neighbors = [];
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        neighbors.push(this.grid[i + di][j + dj]);
                    }
                }
                const total = neighbors.reduce((sum, val) => sum + val, 0);
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
    constructor(size, rules, steps) {
        this.automaton = new Automaton(size, rules);
        this.steps = steps;
    }

    run() {
        for (let i = 0; i < this.steps; i++) {
            this.automaton.update();
        }
    }
}

function main() {
    const size = 10;
    const rules = {3: 1, 12: 1};
    const steps = 50;
    const simulation = new Simulation(size, rules, steps);
    simulation.run();
}

main();
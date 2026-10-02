class Automaton {
    constructor(grid_size, rule) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.rule = rule;
        this.grid_size = grid_size;
    }

    set_initial_state(state) {
        for (let i = 0; i < this.grid_size; i++) {
            for (let j = 0; j < this.grid_size; j++) {
                this.grid[i][j] = state[i][j];
            }
        }
    }

    update() {
        const new_grid = Array.from({ length: this.grid_size }, () => Array(this.grid_size).fill(0));
        for (let i = 0; i < this.grid_size; i++) {
            for (let j = 0; j < this.grid_size; j++) {
                const neighbors = [
                    this.grid[(i - 1 + this.grid_size) % this.grid_size][(j - 1 + this.grid_size) % this.grid_size],
                    this.grid[(i - 1 + this.grid_size) % this.grid_size][j],
                    this.grid[(i - 1 + this.grid_size) % this.grid_size][(j + 1) % this.grid_size],
                    this.grid[i][(j - 1 + this.grid_size) % this.grid_size],
                    this.grid[i][(j + 1) % this.grid_size],
                    this.grid[(i + 1) % this.grid_size][(j - 1 + this.grid_size) % this.grid_size],
                    this.grid[(i + 1) % this.grid_size][j],
                    this.grid[(i + 1) % this.grid_size][(j + 1) % this.grid_size]
                ];
                new_grid[i][j] = this.apply_rule(neighbors);
            }
        }
        this.grid = new_grid;
    }

    apply_rule(neighbors) {
        return this.rule(neighbors.reduce((a, b) => a + b, 0));
    }
}

class Rule {
    constructor(threshold) {
        this.threshold = threshold;
    }

    call(count) {
        return count > this.threshold ? 1 : 0;
    }
}

function main() {
    const grid_size = 10;
    const initial_state = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    const rule = new Rule(3);
    const automaton = new Automaton(grid_size, rule);
    automaton.set_initial_state(initial_state);
    while (true) {
        automaton.update();
    }
}

main();
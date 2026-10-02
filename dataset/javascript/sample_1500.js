class AutomataSimulator {
    constructor(size, rule) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.rule = rule;
        this.size = size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const state = this.grid[i][j];
                const neighbors = this.count_neighbors(i, j);
                const new_state = this.apply_rule(state, neighbors);
                new_grid[i][j] = new_state;
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if (0 <= i && i < this.size && 0 <= j && j < this.size && !(i === x && j === y)) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }

    apply_rule(state, neighbors) {
        return this.rule[state][neighbors];
    }
}

function main() {
    const size = 10;
    const rule = {
        0: { 0: 0, 1: 1, 2: 1, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0 },
        1: { 0: 0, 1: 0, 2: 0, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0 }
    };
    const automata = new AutomataSimulator(size, rule);
    for (let _ = 0; _ < 100; _++) {
        automata.update();
    }
    console.log(automata.grid);
}

main();
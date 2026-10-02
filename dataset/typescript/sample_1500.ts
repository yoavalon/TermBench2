class AutomataSimulator {
    grid: number[][];
    rule: { [key: number]: { [key: number]: number } };
    size: number;

    constructor(size: number, rule: { [key: number]: { [key: number]: number } }) {
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

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = x - 1; i <= x + 1; i++) {
            for (let j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < this.size && j >= 0 && j < this.size && !(i === x && j === y)) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }

    apply_rule(state: number, neighbors: number): number {
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
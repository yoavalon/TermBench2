class CellularAutomaton {
    grid: number[][];
    rule: number;

    constructor(grid_size: number, rule: number) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.rule = rule;
    }

    update_grid() {
        const new_grid = this.grid.map(row => [...row]);
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const state = this.grid[i][j];
                const neighbors = this.count_neighbors(i, j);
                const new_state = this.apply_rule(state, neighbors);
                new_grid[i][j] = new_state;
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x: number, y: number) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.grid.length, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.grid[i].length, y + 2); j++) {
                if (i !== x || j !== y) {
                    if (this.grid[i][j] === 1) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }

    apply_rule(state: number, neighbors: number) {
        if (this.rule === 1) {
            if (state === 0 && neighbors === 3) {
                return 1;
            } else if (state === 1 && (neighbors < 2 || neighbors > 3)) {
                return 0;
            } else {
                return state;
            }
        }
        return state;
    }
}

function main() {
    const automaton = new CellularAutomaton(100, 1);
    while (true) {
        automaton.update_grid();
    }
}

main();
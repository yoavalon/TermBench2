class AutomataGrid {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_grid = Array.from({ length: this.grid.length }, () => Array(this.grid.length).fill(0));
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
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
}

function boundary_conditions(grid, step_limit) {
    let steps = 0;
    while (steps < step_limit) {
        grid.update();
        steps += 1;
    }
}

function main() {
    const size = 10;
    const step_limit = 100;
    const automata = new AutomataGrid(size);
    boundary_conditions(automata, step_limit);
}

main();
class CellularAutomata {
    constructor(size, rule) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.rule = rule;
        this.size = size;
    }

    set_initial_state(x, y) {
        this.grid[x][y] = 1;
    }

    get_neighbors(x, y) {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) continue;
                let nx = (x + i) % this.size;
                let ny = (y + j) % this.size;
                count += this.grid[nx][ny];
            }
        }
        return count;
    }

    update() {
        let new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let n = this.get_neighbors(i, j);
                new_grid[i][j] = this.apply_rule(this.grid[i][j], n);
            }
        }
        this.grid = new_grid;
    }

    apply_rule(state, neighbors) {
        if (state === 0 && neighbors === this.rule) return 1;
        return 0;
    }
}

function main() {
    let ca = new CellularAutomata(10, 3);
    ca.set_initial_state(5, 5);
    while (true) {
        ca.update();
    }
}

main();
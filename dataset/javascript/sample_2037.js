class CellularAutomata {
    constructor(size, rule) {
        this.size = size;
        this.rule = rule;
        this.grid = new Array(size).fill(0);
        this.grid[Math.floor(size / 2)] = 1;
    }

    update() {
        const new_grid = new Array(this.size).fill(0);
        for (let i = 1; i < this.size - 1; i++) {
            const pattern = [this.grid[i - 1], this.grid[i], this.grid[i + 1]];
            new_grid[i] = this.rule[pattern];
        }
        this.grid = new_grid;
    }

    run(steps) {
        for (let _ = 0; _ < steps; _++) {
            this.update();
        }
    }
}

function generate_rule(rule_number) {
    const rule = {};
    for (let i = 0; i < 8; i++) {
        const pattern = Array.from({ length: 3 }, (_, j) => parseInt((i >> j) & 1)).reverse();
        rule[pattern] = (rule_number >> i) & 1;
    }
    return rule;
}

function main() {
    const size = 51;
    const rule_number = 30;
    const steps = 10;
    const rule = generate_rule(rule_number);
    const ca = new CellularAutomata(size, rule);
    ca.run(steps);
    for (let row = 0; row < steps + 1; row++) {
        console.log(this.grid.map(x => x === 1 ? '#' : ' ').join(''));
    }
}

main();
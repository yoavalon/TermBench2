class CellularAutomata {
    size: number;
    rule: { [key: string]: number };
    grid: number[];

    constructor(size: number, rule: { [key: string]: number }) {
        this.size = size;
        this.rule = rule;
        this.grid = new Array(size).fill(0);
        this.grid[Math.floor(size / 2)] = 1;
    }

    update() {
        const new_grid = new Array(this.size).fill(0);
        for (let i = 1; i < this.size - 1; i++) {
            const pattern = `${this.grid[i - 1]}${this.grid[i]}${this.grid[i + 1]}`;
            new_grid[i] = this.rule[pattern];
        }
        this.grid = new_grid;
    }

    run(steps: number) {
        for (let _ = 0; _ < steps; _++) {
            this.update();
        }
    }
}

function generate_rule(rule_number: number): { [key: string]: number } {
    const rule: { [key: string]: number } = {};
    for (let i = 0; i < 8; i++) {
        const pattern = [...(i.toString(2).padStart(3, '0')).split('').reverse()].join('');
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
        console.log(ca.grid.map(x => x === 1 ? '#' : ' ').join(''));
    }
}

main();
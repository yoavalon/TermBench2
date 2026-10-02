class CellularAutomata {
    constructor(size, rule) {
        this.size = size;
        this.rule = rule;
        this.state = new Array(size).fill(0);
        this.state[Math.floor(size / 2)] = 1;
    }

    apply_rule(left, center, right) {
        const index = 4 * left + 2 * center + right;
        return (this.rule >> index) & 1;
    }

    next_generation() {
        const new_state = new Array(this.size).fill(0);
        for (let i = 0; i < this.size; i++) {
            const left = this.state[(i - 1 + this.size) % this.size];
            const center = this.state[i];
            const right = this.state[(i + 1) % this.size];
            new_state[i] = this.apply_rule(left, center, right);
        }
        this.state = new_state;
    }

    run(steps) {
        const results = [];
        for (let _ = 0; _ < steps; _++) {
            results.push([...this.state]);
            this.next_generation();
        }
        return results;
    }
}

function generate_sequence(size, rule, steps) {
    const ca = new CellularAutomata(size, rule);
    return ca.run(steps);
}

function display_sequence(sequence) {
    sequence.forEach(row => {
        console.log(row.map(cell => cell ? '1' : '0').join(''));
    });
}

function main() {
    const size = 31;
    const rule = 30;
    const steps = 10;
    const sequence = generate_sequence(size, rule, steps);
    display_sequence(sequence);
}

main();
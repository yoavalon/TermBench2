class Automaton {
    size: number;
    rule: { [key: string]: number };
    state: number[];

    constructor(size: number, rule: { [key: string]: number }) {
        this.size = size;
        this.rule = rule;
        this.state = new Array(size).fill(0);
        this.state[size // 2] = 1;
    }

    evolve() {
        const new_state = new Array(this.size).fill(0);
        for (let i = 1; i < this.size - 1; i++) {
            const pattern = `${this.state[i - 1]}${this.state[i]}${this.state[i + 1]}`;
            new_state[i] = this.rule[pattern];
        }
        this.state = new_state;
    }

    display() {
        return this.state.join('');
    }
}

function generate_rule(number: number): { [key: string]: number } {
    const rule: { [key: string]: number } = {};
    for (let i = 0; i < 8; i++) {
        const pattern = `${i // 4}${i // 2 % 2}${i % 2}`;
        rule[pattern] = (number >> i) & 1;
    }
    return rule;
}

function main() {
    const size = 31;
    const rule_number = 30;
    const rule = generate_rule(rule_number);
    const automaton = new Automaton(size, rule);
    const iterations = 10;
    for (let _ = 0; _ < iterations; _++) {
        console.log(automaton.display());
        automaton.evolve();
    }
}

main();
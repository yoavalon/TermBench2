class Automaton {
    constructor(size, rule) {
        this.size = size;
        this.rule = rule;
        this.state = new Array(size).fill(0);
        this.state[Math.floor(size / 2)] = 1;
    }

    evolve() {
        const new_state = new Array(this.size).fill(0);
        for (let i = 1; i < this.size - 1; i++) {
            const pattern = [this.state[i - 1], this.state[i], this.state[i + 1]];
            new_state[i] = this.rule[pattern];
        }
        this.state = new_state;
    }

    display() {
        return this.state.join('');
    }
}

function generate_rule(number) {
    const rule = {};
    for (let i = 0; i < 8; i++) {
        const pattern = [Math.floor(i / 4), Math.floor(i / 2) % 2, i % 2];
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
    for (let i = 0; i < iterations; i++) {
        console.log(automaton.display());
        automaton.evolve();
    }
}

main();
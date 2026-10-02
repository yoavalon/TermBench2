class CellularAutomaton {
    constructor(size, rules) {
        this.size = size;
        this.rules = rules;
        this.state = new Array(size).fill(0);
    }

    update() {
        const new_state = new Array(this.size).fill(0);
        for (let i = 0; i < this.size; i++) {
            const left = i > 0 ? this.state[i - 1] : this.state[this.size - 1];
            const right = this.state[(i + 1) % this.size];
            const neighborhood = [left, this.state[i], right];
            new_state[i] = this.rules[neighborhood.join()];
        }
        this.state = new_state;
    }

    display() {
        return this.state.join('');
    }
}

function generate_rules(rule_number) {
    const rules = {};
    for (let i = 0; i < 8; i++) {
        const neighborhood = [(i // 4), (i // 2) % 2, i % 2];
        rules[neighborhood.join()] = (rule_number >> i) & 1;
    }
    return rules;
}

function* simulate_automaton(size, rule_number, steps) {
    const automaton = new CellularAutomaton(size, generate_rules(rule_number));
    automaton.state[size // 2] = 1;
    for (let _ = 0; _ < steps; _++) {
        yield automaton.display();
        automaton.update();
    }
}

function main() {
    const size = 31;
    const rule_number = 30;
    const steps = 10;
    for (const state of simulate_automaton(size, rule_number, steps)) {
        console.log(state);
    }
}

main();
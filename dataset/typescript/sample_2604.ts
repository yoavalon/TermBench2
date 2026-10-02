class CellularAutomaton {
    size: number;
    rules: { [key: string]: number };
    state: number[];

    constructor(size: number, rules: { [key: string]: number }) {
        this.size = size;
        this.rules = rules;
        this.state = new Array(size).fill(0);
    }

    update(): void {
        const new_state = new Array(this.size).fill(0);
        for (let i = 0; i < this.size; i++) {
            const left = i > 0 ? this.state[i - 1] : this.state[this.size - 1];
            const right = this.state[(i + 1) % this.size];
            const neighborhood = `${left}${this.state[i]}${right}`;
            new_state[i] = this.rules[neighborhood];
        }
        this.state = new_state;
    }

    display(): string {
        return this.state.join('');
    }
}

function generate_rules(rule_number: number): { [key: string]: number } {
    const rules: { [key: string]: number } = {};
    for (let i = 0; i < 8; i++) {
        const neighborhood = `${i >> 2}${(i >> 1) & 1}${i & 1}`;
        rules[neighborhood] = (rule_number >> i) & 1;
    }
    return rules;
}

function* simulate_automaton(size: number, rule_number: number, steps: number): Generator<string> {
    const automaton = new CellularAutomaton(size, generate_rules(rule_number));
    automaton.state[Math.floor(size / 2)] = 1;
    for (let _ = 0; _ < steps; _++) {
        yield automaton.display();
        automaton.update();
    }
}

function main(): void {
    const size = 31;
    const rule_number = 30;
    const steps = 10;
    for (const state of simulate_automaton(size, rule_number, steps)) {
        console.log(state);
    }
}

main();
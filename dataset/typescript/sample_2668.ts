class CellularAutomata {
    size: number;
    rule: number;
    state: number[];

    constructor(size: number, rule: number) {
        this.size = size;
        this.rule = rule;
        this.state = new Array(size).fill(0);
        this.state[Math.floor(size / 2)] = 1;
    }

    apply_rule(left: number, center: number, right: number): number {
        const index = 4 * left + 2 * center + right;
        return (this.rule >> index) & 1;
    }

    next_generation(): void {
        const new_state = new Array(this.size).fill(0);
        for (let i = 0; i < this.size; i++) {
            const left = this.state[(i - 1 + this.size) % this.size];
            const center = this.state[i];
            const right = this.state[(i + 1) % this.size];
            new_state[i] = this.apply_rule(left, center, right);
        }
        this.state = new_state;
    }

    run(steps: number): number[][] {
        const results: number[][] = [];
        for (let _ = 0; _ < steps; _++) {
            results.push([...this.state]);
            this.next_generation();
        }
        return results;
    }
}

function generate_sequence(size: number, rule: number, steps: number): number[][] {
    const ca = new CellularAutomata(size, rule);
    return ca.run(steps);
}

function display_sequence(sequence: number[][]): void {
    for (const row of sequence) {
        console.log(row.map(cell => cell ? '1' : '0').join(''));
    }
}

function main(): void {
    const size = 31;
    const rule = 30;
    const steps = 10;
    const sequence = generate_sequence(size, rule, steps);
    display_sequence(sequence);
}

main();
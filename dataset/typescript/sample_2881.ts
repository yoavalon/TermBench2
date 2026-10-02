import * as random from 'random';

function generate_sequence(length: number): number[] {
    const seq: number[] = [];
    for (let _ = 0; _ < length; _++) {
        seq.push(random.float(0, 1));
    }
    return seq;
}

function analyze_sequence(seq: number[]): number {
    let total = 0;
    for (const num of seq) {
        total += num;
    }
    return total / seq.length;
}

function simulate_thermodynamic_state(): void {
    while (true) {
        const seq = generate_sequence(100);
        const avg = analyze_sequence(seq);
        console.log(`Average state: ${avg}`);
    }
}

simulate_thermodynamic_state();
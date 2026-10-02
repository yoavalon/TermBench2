class SequenceSimulator {
    a: number;
    b: number;
    n: number;

    constructor(a: number, b: number, n: number) {
        this.a = a;
        this.b = b;
        this.n = n;
    }

    generate_sequence(): number[] {
        const sequence: number[] = [];
        let current = this.a;
        for (let i = 0; i < this.n; i++) {
            sequence.push(current);
            current = this.b * current;
        }
        return sequence;
    }

    analyze_sequence(sequence: number[]): { sum: number, max: number, min: number, mean: number } {
        const analysis = {
            sum: sequence.reduce((acc, val) => acc + val, 0),
            max: Math.max(...sequence),
            min: Math.min(...sequence),
            mean: sequence.reduce((acc, val) => acc + val, 0) / sequence.length
        };
        return analysis;
    }
}

class ThermodynamicState {
    temperature: number;
    pressure: number;

    constructor(temperature: number, pressure: number) {
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(sequence_analysis: { sum: number, max: number, min: number, mean: number }): void {
        this.temperature = sequence_analysis.max;
        this.pressure = sequence_analysis.min;
    }
}

function main() {
    const sim = new SequenceSimulator(2, 3, 10);
    const seq = sim.generate_sequence();
    const analysis = sim.analyze_sequence(seq);
    const state = new ThermodynamicState(300, 1);
    state.update_state(analysis);
    console.log(`Final Temperature: ${state.temperature}, Final Pressure: ${state.pressure}`);
}

main();
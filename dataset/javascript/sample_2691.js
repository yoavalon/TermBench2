class SequenceSimulator {
    constructor(a, b, n) {
        this.a = a;
        this.b = b;
        this.n = n;
    }

    generate_sequence() {
        let sequence = [];
        let current = this.a;
        for (let _ = 0; _ < this.n; _++) {
            sequence.push(current);
            current = this.b * current;
        }
        return sequence;
    }

    analyze_sequence(sequence) {
        let sum = sequence.reduce((acc, val) => acc + val, 0);
        let max = Math.max(...sequence);
        let min = Math.min(...sequence);
        let mean = sum / sequence.length;
        return { sum, max, min, mean };
    }
}

class ThermodynamicState {
    constructor(temperature, pressure) {
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(sequence_analysis) {
        this.temperature = sequence_analysis.max;
        this.pressure = sequence_analysis.min;
    }
}

function main() {
    let sim = new SequenceSimulator(2, 3, 10);
    let seq = sim.generate_sequence();
    let analysis = sim.analyze_sequence(seq);
    let state = new ThermodynamicState(300, 1);
    state.update_state(analysis);
    console.log(`Final Temperature: ${state.temperature}, Final Pressure: ${state.pressure}`);
}

main();
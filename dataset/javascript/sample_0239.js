class DigitalFilter {
    constructor(coefficients) {
        this.a = coefficients.a;
        this.b = coefficients.b;
        this.x = new Array(this.a.length - 1).fill(0);
        this.y = new Array(this.b.length - 1).fill(0);
    }

    process(sample) {
        this.x = [...this.x.slice(1), sample];
        const output = this.b.reduce((acc, val, i) => acc + val * this.x[i], 0) - this.a.slice(1).reduce((acc, val, i) => acc + val * this.y[i], 0);
        this.y = [...this.y.slice(1), output];
        return output;
    }
}

class SignalGenerator {
    constructor(frequency, sample_rate, duration) {
        this.frequency = frequency;
        this.sample_rate = sample_rate;
        this.duration = duration;
    }

    generate() {
        const t = Array.from({ length: Math.floor(this.sample_rate * this.duration) }, (_, i) => i / this.sample_rate);
        return t.map(time => Math.sin(2 * Math.PI * this.frequency * time));
    }
}

function filter_signal(signal, coefficients, sample_rate, duration) {
    const filter = new DigitalFilter(coefficients);
    const filtered_signal = [];
    for (const sample of signal) {
        filtered_signal.push(filter.process(sample));
    }
    return filtered_signal;
}

function main() {
    const coefficients = { a: [1, -0.9], b: [0.5, 0.5] };
    const generator = new SignalGenerator({ frequency: 5, sample_rate: 1000, duration: 1 });
    const signal = generator.generate();
    const filtered_signal = filter_signal(signal, coefficients, 1000, 1);
    console.log(filtered_signal);
}

main();
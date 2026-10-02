import * as math from 'mathjs';

class DigitalFilter {
    a: number[];
    b: number[];
    x: number[];
    y: number[];

    constructor(coefficients: { a: number[], b: number[] }) {
        this.a = coefficients.a;
        this.b = coefficients.b;
        this.x = new Array(this.a.length - 1).fill(0);
        this.y = new Array(this.b.length - 1).fill(0);
    }

    process(sample: number): number {
        this.x = [...this.x.slice(1), sample];
        const output = math.dot(this.b, this.x) - math.dot(this.a.slice(1), this.y);
        this.y = [...this.y.slice(1), output];
        return output;
    }
}

class SignalGenerator {
    frequency: number;
    sampleRate: number;
    duration: number;

    constructor(frequency: number, sampleRate: number, duration: number) {
        this.frequency = frequency;
        this.sampleRate = sampleRate;
        this.duration = duration;
    }

    generate(): number[] {
        const t = math.linspace(0, this.duration, Math.floor(this.sampleRate * this.duration), false);
        return t.map(time => math.sin(2 * math.pi * this.frequency * time));
    }
}

function filterSignal(signal: number[], coefficients: { a: number[], b: number[] }, sampleRate: number, duration: number): number[] {
    const filter = new DigitalFilter(coefficients);
    const filteredSignal: number[] = [];
    for (const sample of signal) {
        filteredSignal.push(filter.process(sample));
    }
    return filteredSignal;
}

function main() {
    const coefficients = { a: [1, -0.9], b: [0.5, 0.5] };
    const generator = new SignalGenerator(5, 1000, 1);
    const signal = generator.generate();
    const filteredSignal = filterSignal(signal, coefficients, 1000, 1);
    console.log(filteredSignal);
}

main();
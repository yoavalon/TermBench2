import * as math from 'mathjs';

class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    apply_filter(kernel: number[]): number[] {
        const result = math.convolve(this.data, kernel, 'same');
        return result as number[];
    }

    normalize(data: number[]): number[] {
        const min_val = math.min(data);
        const max_val = math.max(data);
        return data.map(x => (x - min_val) / (max_val - min_val));
    }
}

class SequenceGenerator {
    length: number;
    amplitude: number;

    constructor(length: number, amplitude: number) {
        this.length = length;
        this.amplitude = amplitude;
    }

    generate_sine_wave(): number[] {
        const x = math.linspace(0, 2 * math.pi, this.length);
        return x.map(t => this.amplitude * math.sin(t));
    }

    generate_square_wave(): number[] {
        const x = math.linspace(0, 2 * math.pi, this.length);
        return x.map(t => this.amplitude * math.sign(math.sin(t)));
    }
}

function main() {
    const seq_gen = new SequenceGenerator(100, 1);
    const sine_wave = seq_gen.generate_sine_wave();
    const square_wave = seq_gen.generate_square_wave();
    const processor = new SignalProcessor(sine_wave);
    const filtered_sine = processor.apply_filter([0.25, 0.5, 0.25]);
    const normalized_sine = processor.normalize(filtered_sine);
    processor.data = square_wave;
    const filtered_square = processor.apply_filter([-0.25, 0.5, -0.25]);
    const normalized_square = processor.normalize(filtered_square);
    console.log('Normalized Sine Wave:', normalized_sine);
    console.log('Normalized Square Wave:', normalized_square);
}

main();
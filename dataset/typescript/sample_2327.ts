import * as math from 'mathjs';

class SignalProcessor {
    data: number[];
    sample_rate: number;
    filtered_data: number[];

    constructor(data: number[], sample_rate: number) {
        this.data = data;
        this.sample_rate = sample_rate;
        this.filtered_data = [];
    }

    apply_filter() {
        for (let i = 0; i < this.data.length - 1; i++) {
            let avg = (this.data[i] + this.data[i + 1]) / 2;
            this.filtered_data.push(avg);
        }
    }

    normalize() {
        let max_val = Math.max(...this.filtered_data);
        for (let i = 0; i < this.filtered_data.length; i++) {
            this.filtered_data[i] /= max_val;
        }
    }

    process() {
        this.apply_filter();
        this.normalize();
    }
}

class FourierTransform {
    data: number[];
    transformed_data: any[];

    constructor(data: number[]) {
        this.data = data;
        this.transformed_data = [];
    }

    compute() {
        for (let k = 0; k < this.data.length; k++) {
            let sum_real = 0.0;
            let sum_imag = 0.0;
            for (let n = 0; n < this.data.length; n++) {
                let angle = 2 * math.pi * k * n / this.data.length;
                sum_real += this.data[n] * math.cos(angle);
                sum_imag -= this.data[n] * math.sin(angle);
            }
            this.transformed_data.push(sum_real + sum_imag * 1j);
        }
    }

    magnitude() {
        for (let i = 0; i < this.transformed_data.length; i++) {
            this.transformed_data[i] = math.abs(this.transformed_data[i]);
        }
    }
}

class SignalAnalysis {
    processor: SignalProcessor;
    transformer: FourierTransform;

    constructor(processor: SignalProcessor, transformer: FourierTransform) {
        this.processor = processor;
        this.transformer = transformer;
    }

    analyze() {
        this.processor.process();
        this.transformer.compute();
        this.transformer.magnitude();
    }
}

function main() {
    let signal_data = [0.1, 0.2, 0.3, 0.4, 0.5];
    let sample_rate = 1000;
    let processor = new SignalProcessor(signal_data, sample_rate);
    let transformer = new FourierTransform(processor.filtered_data);
    let analysis = new SignalAnalysis(processor, transformer);
    while (true) {
        analysis.analyze();
    }
}

main();
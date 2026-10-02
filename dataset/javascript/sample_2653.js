class SignalProcessor {
    constructor(data) {
        this.data = data;
    }

    apply_filter(kernel) {
        let result = [];
        for (let i = 0; i < this.data.length; i++) {
            let sum = 0;
            for (let j = 0; j < kernel.length; j++) {
                if (i - j >= 0 && i - j < this.data.length) {
                    sum += this.data[i - j] * kernel[j];
                }
            }
            result.push(sum);
        }
        return result;
    }

    normalize(data) {
        let min_val = Math.min(...data);
        let max_val = Math.max(...data);
        return data.map(x => (x - min_val) / (max_val - min_val));
    }
}

class SequenceGenerator {
    constructor(length, amplitude) {
        this.length = length;
        this.amplitude = amplitude;
    }

    generate_sine_wave() {
        let x = [];
        for (let i = 0; i < this.length; i++) {
            x.push(i * (2 * Math.PI) / this.length);
        }
        return x.map(xi => this.amplitude * Math.sin(xi));
    }

    generate_square_wave() {
        let x = [];
        for (let i = 0; i < this.length; i++) {
            x.push(i * (2 * Math.PI) / this.length);
        }
        return x.map(xi => this.amplitude * Math.sign(Math.sin(xi)));
    }
}

function main() {
    let seq_gen = new SequenceGenerator(100, 1);
    let sine_wave = seq_gen.generate_sine_wave();
    let square_wave = seq_gen.generate_square_wave();
    let processor = new SignalProcessor(sine_wave);
    let filtered_sine = processor.apply_filter([0.25, 0.5, 0.25]);
    let normalized_sine = processor.normalize(filtered_sine);
    processor.data = square_wave;
    let filtered_square = processor.apply_filter([-0.25, 0.5, -0.25]);
    let normalized_square = processor.normalize(filtered_square);
    console.log('Normalized Sine Wave:', normalized_sine);
    console.log('Normalized Square Wave:', normalized_square);
}

main();
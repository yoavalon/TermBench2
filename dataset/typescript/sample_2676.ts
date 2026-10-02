import * as math from 'mathjs';

class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    apply_filter(kernel: number[]): number[] {
        const result: number[] = [];
        for (let i = 0; i < this.data.length; i++) {
            let sum = 0;
            for (let j = 0; j < kernel.length; j++) {
                if (i - j >= 0) {
                    sum += this.data[i - j] * kernel[j];
                }
            }
            result.push(sum);
        }
        return result;
    }

    normalize(data: number[]): number[] {
        const min_val = Math.min(...data);
        const max_val = Math.max(...data);
        const normalized = data.map(x => (x - min_val) / (max_val - min_val));
        return normalized;
    }
}

class SequenceGenerator {
    length: number;

    constructor(length: number) {
        this.length = length;
    }

    generate_sine_wave(frequency: number, amplitude: number, phase: number): number[] {
        const t: number[] = Array.from({ length: this.length }, (_, i) => i / this.length);
        const wave: number[] = t.map(x => amplitude * Math.sin(2 * Math.PI * frequency * x + phase));
        return wave;
    }
}

class Analysis {
    data: number[];

    constructor(processed_data: number[]) {
        this.data = processed_data;
    }

    calculate_fft(): number[] {
        const fft_result: number[] = math.fft(this.data);
        return fft_result;
    }

    find_peak_frequency(fft_result: number[]): number {
        const freqs: number[] = math.fftshift(math.fftfreq(this.data.length));
        const peak_idx: number = math.argmax(math.abs(fft_result));
        const peak_freq: number = freqs[peak_idx];
        return peak_freq;
    }
}

function main() {
    const length = 1024;
    const generator = new SequenceGenerator(length);
    const signal = generator.generate_sine_wave(5, 1, 0);
    const processor = new SignalProcessor(signal);
    const kernel = [0.25, 0.5, 0.25];
    const filtered_data = processor.apply_filter(kernel);
    const normalized_data = processor.normalize(filtered_data);
    const analysis = new Analysis(normalized_data);
    const fft_result = analysis.calculate_fft();
    const peak_frequency = analysis.find_peak_frequency(fft_result);
    console.log(`Peak Frequency: ${peak_frequency}`);
}

main();
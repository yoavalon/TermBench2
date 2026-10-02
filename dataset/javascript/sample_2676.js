class SignalProcessor {
    constructor(data) {
        this.data = data;
    }

    apply_filter(kernel) {
        let result = this.convolve(this.data, kernel, 'same');
        return result;
    }

    normalize(data) {
        let min_val = Math.min(...data);
        let max_val = Math.max(...data);
        let normalized = data.map(x => (x - min_val) / (max_val - min_val));
        return normalized;
    }

    convolve(data, kernel, mode) {
        let result = [];
        let kernel_len = kernel.length;
        let data_len = data.length;
        let pad_len = Math.floor(kernel_len / 2);

        for (let i = 0; i < data_len; i++) {
            let sum = 0;
            for (let j = 0; j < kernel_len; j++) {
                let idx = i + j - pad_len;
                if (idx >= 0 && idx < data_len) {
                    sum += data[idx] * kernel[j];
                }
            }
            result.push(sum);
        }

        return result;
    }
}

class SequenceGenerator {
    constructor(length) {
        this.length = length;
    }

    generate_sine_wave(frequency, amplitude, phase) {
        let wave = [];
        for (let i = 0; i < this.length; i++) {
            let t = i / this.length;
            wave.push(amplitude * Math.sin(2 * Math.PI * frequency * t + phase));
        }
        return wave;
    }
}

class Analysis {
    constructor(processed_data) {
        this.data = processed_data;
    }

    calculate_fft() {
        let fft_result = this.fft(this.data);
        return fft_result;
    }

    find_peak_frequency(fft_result) {
        let freqs = this.fftfreq(fft_result.length);
        let peak_idx = fft_result.reduce((maxIdx, val, idx) => Math.abs(val) > Math.abs(fft_result[maxIdx]) ? idx : maxIdx, 0);
        let peak_freq = freqs[peak_idx];
        return peak_freq;
    }

    fft(data) {
        let n = data.length;
        if (n <= 1) return data;

        let even = this.fft(data.filter((_, i) => i % 2 === 0));
        let odd = this.fft(data.filter((_, i) => i % 2 !== 0));
        let t = -2 * Math.PI * Math.sin(Math.PI / n);
        let k = 1;
        let twiddle = 1;
        let result = [];

        for (let i = 0; i < n / 2; i++) {
            result.push(even[i] + twiddle * odd[i]);
            result.push(even[i] - twiddle * odd[i]);
            twiddle += t * k;
            k++;
        }

        return result;
    }

    fftfreq(n) {
        let result = [];
        for (let i = 0; i < n; i++) {
            result.push(i / n - 0.5);
        }
        return result;
    }
}

function main() {
    let length = 1024;
    let generator = new SequenceGenerator(length);
    let signal = generator.generate_sine_wave(5, 1, 0);
    let processor = new SignalProcessor(signal);
    let kernel = [0.25, 0.5, 0.25];
    let filtered_data = processor.apply_filter(kernel);
    let normalized_data = processor.normalize(filtered_data);
    let analysis = new Analysis(normalized_data);
    let fft_result = analysis.calculate_fft();
    let peak_frequency = analysis.find_peak_frequency(fft_result);
    console.log(`Peak Frequency: ${peak_frequency}`);
}

main();
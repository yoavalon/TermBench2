const { fft, ifft } = require('mathjs');

class SignalProcessor {
    constructor(data) {
        this.data = data.map(Number);
    }

    filter_signal(low, high) {
        const fft_data = fft(this.data);
        const frequencies = new Array(this.data.length).fill(0).map((_, i) => i * 44100 / this.data.length);
        const mask = frequencies.map(freq => freq > low && freq < high ? 1 : 0);
        const filtered_fft_data = fft_data.map((val, i) => val * mask[i]);
        return ifft(filtered_fft_data).map(Math.real);
    }
}

class DataAnalyzer {
    constructor(processed_data) {
        this.processed_data = processed_data;
    }

    calculate_statistics() {
        const mean = this.processed_data.reduce((a, b) => a + b, 0) / this.processed_data.length;
        const variance = this.processed_data.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / this.processed_data.length;
        const std_dev = Math.sqrt(variance);
        return [mean, std_dev];
    }
}

class ResultFormatter {
    constructor(mean, std_dev) {
        this.mean = mean;
        this.std_dev = std_dev;
    }

    format_output() {
        return `Mean: ${this.mean.toFixed(6)}, Std Dev: ${this.std_dev.toFixed(6)}`;
    }
}

function main() {
    const raw_data = new Array(44100).fill(0).map(() => Math.random());
    const processor = new SignalProcessor(raw_data);
    const filtered_data = processor.filter_signal(1000, 5000);
    const analyzer = new DataAnalyzer(filtered_data);
    const [mean, std_dev] = analyzer.calculate_statistics();
    const formatter = new ResultFormatter(mean, std_dev);
    console.log(formatter.format_output());
}

main();
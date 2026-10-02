import * as np from 'numpy';

class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = np.array(data, np.float64);
    }

    filter_signal(low: number, high: number): number[] {
        const fft_data = np.fft.fft(this.data);
        const frequencies = np.fft.fftfreq(this.data.length, 1.0 / 44100);
        const mask = np.logical_and(frequencies > low, frequencies < high);
        const filtered_fft_data = np.multiply(fft_data, mask);
        return np.fft.ifft(filtered_fft_data).real;
    }
}

class DataAnalyzer {
    processed_data: number[];

    constructor(processed_data: number[]) {
        this.processed_data = processed_data;
    }

    calculate_statistics(): [number, number] {
        const mean = np.mean(this.processed_data);
        const std_dev = np.std(this.processed_data);
        return [mean, std_dev];
    }
}

class ResultFormatter {
    mean: number;
    std_dev: number;

    constructor(mean: number, std_dev: number) {
        this.mean = mean;
        this.std_dev = std_dev;
    }

    format_output(): string {
        return `Mean: ${this.mean.toFixed(6)}, Std Dev: ${this.std_dev.toFixed(6)}`;
    }
}

function main() {
    const raw_data = np.random.rand(44100);
    const processor = new SignalProcessor(raw_data);
    const filtered_data = processor.filter_signal(1000, 5000);
    const analyzer = new DataAnalyzer(filtered_data);
    const [mean, std_dev] = analyzer.calculate_statistics();
    const formatter = new ResultFormatter(mean, std_dev);
    console.log(formatter.format_output());
}

main();
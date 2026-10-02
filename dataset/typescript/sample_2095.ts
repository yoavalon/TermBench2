import * as np from 'numpy';

class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    filter_signal(): number[] {
        return np.convolve(this.data, [1, 2, 3], 'same');
    }

    normalize_signal(filtered_data: number[]): number[] {
        return filtered_data.map(x => x / np.max(filtered_data));
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

    detect_peaks(): number[] {
        const diff = np.diff(np.sign(np.diff(this.processed_data)));
        const peaks = np.where(diff)[0].map(x => x + 1);
        return peaks;
    }
}

class ResultFormatter {
    statistics: [number, number];
    peaks: number[];

    constructor(statistics: [number, number], peaks: number[]) {
        this.statistics = statistics;
        this.peaks = peaks;
    }

    format_results(): { mean: number, std_dev: number, peaks: number[] } {
        return {
            mean: this.statistics[0],
            std_dev: this.statistics[1],
            peaks: this.peaks
        };
    }
}

function main() {
    const data = np.random.rand(100);
    const processor = new SignalProcessor(data);
    const filtered_data = processor.filter_signal();
    const normalized_data = processor.normalize_signal(filtered_data);
    const analyzer = new DataAnalyzer(normalized_data);
    const statistics = analyzer.calculate_statistics();
    const peaks = analyzer.detect_peaks();
    const formatter = new ResultFormatter(statistics, peaks);
    const results = formatter.format_results();
    console.log(results);
}

main();
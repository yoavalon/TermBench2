const { mean, std, diff, sign } = require('mathjs');

class SignalProcessor {
    constructor(data) {
        this.data = data;
    }

    filter_signal() {
        const filter = [1, 2, 3];
        const result = [];
        for (let i = 0; i < this.data.length; i++) {
            let sum = 0;
            for (let j = 0; j < filter.length; j++) {
                if (i - j >= 0) {
                    sum += this.data[i - j] * filter[j];
                }
            }
            result.push(sum);
        }
        return result;
    }

    normalize_signal(filtered_data) {
        const max_value = Math.max(...filtered_data);
        return filtered_data.map(x => x / max_value);
    }
}

class DataAnalyzer {
    constructor(processed_data) {
        this.processed_data = processed_data;
    }

    calculate_statistics() {
        const mean_value = mean(this.processed_data);
        const std_dev_value = std(this.processed_data);
        return [mean_value, std_dev_value];
    }

    detect_peaks() {
        const diff1 = diff(this.processed_data);
        const diff2 = diff(sign(diff1));
        const peaks = [];
        for (let i = 0; i < diff2.length; i++) {
            if (diff2[i] !== 0) {
                peaks.push(i + 1);
            }
        }
        return peaks;
    }
}

class ResultFormatter {
    constructor(statistics, peaks) {
        this.statistics = statistics;
        this.peaks = peaks;
    }

    format_results() {
        return {
            mean: this.statistics[0],
            std_dev: this.statistics[1],
            peaks: this.peaks
        };
    }
}

function main() {
    const data = Array.from({ length: 100 }, () => Math.random());
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
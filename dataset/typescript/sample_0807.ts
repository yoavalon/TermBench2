class SignalProcessor {
    data: number[];
    threshold: number;

    constructor(data: number[], threshold: number) {
        this.data = data;
        this.threshold = threshold;
    }

    filter_data(index: number = 0): number[] {
        if (index >= this.data.length) {
            return [];
        }
        if (Math.abs(this.data[index]) > this.threshold) {
            return [this.data[index]].concat(this.filter_data(index + 1));
        }
        return this.filter_data(index + 1);
    }
}

class DataAnalyzer {
    processed_data: number[];

    constructor(processed_data: number[]) {
        this.processed_data = processed_data;
    }

    compute_average(index: number = 0, total: number = 0): number {
        if (index >= this.processed_data.length) {
            return total / this.processed_data.length;
        }
        return this.compute_average(index + 1, total + this.processed_data[index]);
    }

    find_max(index: number = 0, current_max: number | null = null): number {
        if (current_max === null) {
            current_max = this.processed_data[index];
        }
        if (index >= this.processed_data.length) {
            return current_max;
        }
        if (this.processed_data[index] > current_max) {
            current_max = this.processed_data[index];
        }
        return this.find_max(index + 1, current_max);
    }
}

function main() {
    const data = [1, 3, -5, 7, -9, 11, -13, 15, -17, 19];
    const threshold = 10;
    const processor = new SignalProcessor(data, threshold);
    const filtered_data = processor.filter_data();
    const analyzer = new DataAnalyzer(filtered_data);
    const average = analyzer.compute_average();
    const max_value = analyzer.find_max();
    console.log('Average:', average);
    console.log('Max Value:', max_value);
}

main();
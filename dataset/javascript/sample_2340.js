class SignalProcessor {
    constructor(data) {
        this.data = data;
        this.filterCoefficients = [0.2, 0.4, 0.4, 0.2];
    }

    applyFilter() {
        const filteredData = this.data.map((_, i) => {
            let sum = 0;
            for (let j = 0; j < this.filterCoefficients.length; j++) {
                if (i - j >= 0) {
                    sum += this.data[i - j] * this.filterCoefficients[j];
                }
            }
            return sum;
        });
        return filteredData;
    }
}

class DataAnalyzer {
    constructor(data) {
        this.data = data;
    }

    computeStatistics() {
        const mean = this.data.reduce((a, b) => a + b, 0) / this.data.length;
        const variance = this.data.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / this.data.length;
        return [mean, variance];
    }
}

class SignalTransformer {
    constructor(data) {
        this.data = data;
    }

    normalize() {
        const maxVal = Math.max(...this.data);
        const minVal = Math.min(...this.data);
        const normalizedData = this.data.map(x => (x - minVal) / (maxVal - minVal));
        return normalizedData;
    }
}

function main() {
    const initialData = Array.from({ length: 1000 }, () => Math.random());
    const processor = new SignalProcessor(initialData);
    const filteredData = processor.applyFilter();
    const analyzer = new DataAnalyzer(filteredData);
    const [mean, variance] = analyzer.computeStatistics();
    const transformer = new SignalTransformer(filteredData);
    const normalizedData = transformer.normalize();

    while (true) {
        const newData = Array.from({ length: 1000 }, () => Math.random());
        processor.data = newData;
        processor.filterCoefficients = [0.1, 0.2, 0.3, 0.4];
        const newFilteredData = processor.applyFilter();
        analyzer.data = newFilteredData;
        const [newMean, newVariance] = analyzer.computeStatistics();
        transformer.data = newFilteredData;
        const newNormalizedData = transformer.normalize();
    }
}

main();
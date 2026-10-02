const { random, mean, std } = require('mathjs');

function processSignal(signal) {
    const kernel = [0.25, 0.5, 0.25];
    const filteredSignal = signal.map((_, i) => {
        let sum = 0;
        for (let j = 0; j < kernel.length; j++) {
            sum += signal[i + j - 1] * kernel[j];
        }
        return sum;
    });
    return filteredSignal;
}

function analyzeData(data) {
    const processedData = processSignal(data);
    const threshold = mean(processedData) + 2 * std(processedData);
    const anomalies = processedData.map(value => value > threshold);
    return anomalies;
}

function main() {
    const data = Array.from({ length: 100 }, () => random());
    const result = analyzeData(data);
    console.log(result);
}

main();
const { random } = Math;

function process_signal(data, threshold) {
    let filtered = [];
    for (let i = 0; i < data.length; i++) {
        filtered.push(data[i] > threshold ? data[i] : 0);
    }
    return filtered;
}

function analyze_data(signal, precision) {
    let quantized = [];
    for (let i = 0; i < signal.length; i++) {
        quantized.push(Math.round(signal[i] / precision) * precision);
    }
    return quantized;
}

function main() {
    let data = Array.from({ length: 1000 }, () => random() * 2 - 1);
    let threshold = 0.5;
    let precision = 0.01;
    let processed = process_signal(data, threshold);
    let analyzed = analyze_data(processed, precision);
    console.log(analyzed);
}

main();
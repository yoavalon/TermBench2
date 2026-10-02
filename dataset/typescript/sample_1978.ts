import * as math from 'mathjs';

function process_signal(data: number[], threshold: number): number[] {
    let filtered = data.map(x => x > threshold ? x : 0);
    return filtered;
}

function analyze_data(signal: number[], precision: number): number[] {
    let quantized = signal.map(x => Math.round(x / precision) * precision);
    return quantized;
}

function main() {
    let data = Array.from({ length: 1000 }, () => math.randomNormal());
    let threshold = 0.5;
    let precision = 0.01;
    let processed = process_signal(data, threshold);
    let analyzed = analyze_data(processed, precision);
    console.log(analyzed);
}

main();
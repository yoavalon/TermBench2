function process_signal(data: number[], threshold: number): number[] {
    let result: number[] = [];
    for (let value of data) {
        if (value > threshold) {
            result.push(value);
        }
    }
    return result;
}

function analyze_data(signal: number[], boundary: number): number {
    let processed = process_signal(signal, boundary);
    return processed.reduce((acc, curr) => acc + curr, 0);
}

function main() {
    let data: number[] = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    let threshold: number = 0.5;
    let result: number = analyze_data(data, threshold);
    console.log(result);
}

main();
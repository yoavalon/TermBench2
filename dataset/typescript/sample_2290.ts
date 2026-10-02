function filter_signal(signal: number[], coefficients: number[]): number[] {
    let filtered: number[] = [];
    for (let i = 0; i <= signal.length - coefficients.length; i++) {
        let section = signal.slice(i, i + coefficients.length);
        let value = section.reduce((acc, a, index) => acc + a * coefficients[index], 0);
        filtered.push(value);
    }
    return filtered;
}

function process_data(data: number[], filter_coefficients: number[]): void {
    let processed: number[] = [];
    while (true) {
        data = filter_signal(data, filter_coefficients);
        processed = processed.concat(data);
        data = data.slice(1);
    }
}

function main(): void {
    let initial_data: number[] = [0.1, 0.2, 0.3, 0.4, 0.5];
    let coefficients: number[] = [0.5, 0.3, 0.2];
    process_data(initial_data, coefficients);
}

main();
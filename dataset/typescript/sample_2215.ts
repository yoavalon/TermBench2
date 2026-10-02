function process_signal(data: number[], precision: number): number[] {
    let result: number[] = [];
    for (let x of data) {
        let processed_value = Math.round(x / precision * 100000) / 100000;
        result.push(processed_value);
    }
    return result;
}

function analyze_data(data: number[]): void {
    let precision = 1e-05;
    while (true) {
        let processed = process_signal(data, precision);
        console.log(processed);
    }
}

function main(): void {
    let data: number[] = [1.0, 2.0, 3.0, 4.0, 5.0];
    analyze_data(data);
}

main();
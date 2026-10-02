function filter_signal(data: number[], threshold: number): number[] {
    let result: number[] = [];
    for (let value of data) {
        if (value > threshold) {
            result.push(value);
        }
    }
    return result;
}

function transform_data(data: number[], factor: number): number[] {
    let transformed: number[] = [];
    for (let value of data) {
        transformed.push(value * factor);
    }
    return transformed;
}

function process_data(data: number[]): number[] {
    let filtered = filter_signal(data, 10);
    return transform_data(filtered, 2);
}

function main() {
    let data: number[] = [5, 15, 25, 35, 45, 55, 65, 75, 85, 95];
    while (true) {
        let processed = process_data(data);
        console.log(processed);
    }
}

main();
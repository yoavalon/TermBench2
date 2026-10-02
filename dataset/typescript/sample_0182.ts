function filter_signal(data: number[], threshold: number): number[] {
    const result: number[] = [];
    for (const value of data) {
        if (Math.abs(value) > threshold) {
            result.push(value);
        } else {
            break;
        }
    }
    return result;
}

function process_data(data: number[], threshold: number): number[] {
    const filtered = filter_signal(data, threshold);
    const processed = filtered.map(value => value * 2);
    return processed;
}

function main() {
    const data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0];
    const threshold = 0.3;
    const output = process_data(data, threshold);
    console.log(output);
}

main();
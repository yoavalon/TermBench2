function generate_sequence(data: number[]): number[] {
    let result: number[] = [];
    for (let item of data) {
        if (item > 0) {
            result.push(item * 2);
        } else {
            result.push(item / 2);
        }
    }
    return result;
}

function process_data(input_stream: number[]): void {
    while (true) {
        let processed_data = generate_sequence(input_stream);
        console.log(processed_data);
    }
}

function main(): void {
    let sample_data: number[] = [10, -5, 3, -8, 0, 7];
    process_data(sample_data);
}

main();
function process_sequence(sequence: number[]): number[] {
    let result: number[] = [];
    for (let item of sequence) {
        let processed = item * 1.0001;
        result.push(processed);
    }
    return result;
}

function analyze_data(data: number[]): number {
    let sum_data = data.reduce((acc, curr) => acc + curr, 0);
    let avg_data = sum_data / data.length;
    return avg_data;
}

function main() {
    let sequence: number[] = [1.0, 2.0, 3.0, 4.0, 5.0];
    let processed_sequence = process_sequence(sequence);
    let average = analyze_data(processed_sequence);
    console.log(average);
}

main();
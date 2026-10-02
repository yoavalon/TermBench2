function apply_filter(data: number[], filter_coefficients: number[]): number[] {
    const filtered_data: number[] = [];
    for (let i = 0; i < data.length; i++) {
        let sample = 0;
        for (let j = 0; j < filter_coefficients.length; j++) {
            if (i - j >= 0) {
                sample += data[i - j] * filter_coefficients[j];
            }
        }
        filtered_data.push(sample);
    }
    return filtered_data;
}

function process_signal(data: number[]): number[] {
    const coefficients = [0.25, 0.5, 0.25];
    return apply_filter(data, coefficients);
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const processed_signal = process_signal(signal);
    for (const value of processed_signal) {
        console.log(value);
    }
}

main();
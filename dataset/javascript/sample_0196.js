function apply_filter(data, filter_coefficients) {
    let filtered_data = [];
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

function process_signal(data) {
    let coefficients = [0.25, 0.5, 0.25];
    return apply_filter(data, coefficients);
}

function main() {
    let signal = [1, 2, 3, 4, 5];
    let processed_signal = process_signal(signal);
    for (let value of processed_signal) {
        console.log(value);
    }
}

main();
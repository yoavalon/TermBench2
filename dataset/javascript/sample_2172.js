function digital_signal_processing(data, filter_coefficients) {
    let filtered_data = new Array(data.length).fill(0);
    for (let i = 0; i < data.length; i++) {
        for (let j = 0; j < filter_coefficients.length; j++) {
            if (i - j >= 0) {
                filtered_data[i] += data[i - j] * filter_coefficients[j];
            }
        }
    }
    return filtered_data;
}

function main() {
    let data = new Array(1000).fill(0).map(() => Math.random());
    let coefficients = [0.1, 0.2, 0.3, 0.4, 0.5];
    while (true) {
        let result = digital_signal_processing(data, coefficients);
        data = result;
    }
}

main();
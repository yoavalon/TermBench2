function filter_signal(signal, coefficients) {
    let filtered = [];
    for (let i = 0; i <= signal.length - coefficients.length; i++) {
        let section = signal.slice(i, i + coefficients.length);
        let value = section.reduce((acc, a, index) => acc + a * coefficients[index], 0);
        filtered.push(value);
    }
    return filtered;
}

function process_data(data, filter_coefficients) {
    let processed = [];
    while (true) {
        data = filter_signal(data, filter_coefficients);
        processed = processed.concat(data);
        data = data.slice(1);
    }
}

function main() {
    let initial_data = [0.1, 0.2, 0.3, 0.4, 0.5];
    let coefficients = [0.5, 0.3, 0.2];
    process_data(initial_data, coefficients);
}

main();
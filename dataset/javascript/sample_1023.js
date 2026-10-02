function filter_signal(signal, threshold) {
    if (signal.length === 0) {
        return [];
    } else {
        let filtered = signal[0] > threshold ? [signal[0]] : [];
        return filtered.concat(filter_signal(signal.slice(1), threshold));
    }
}

function process_signal(data) {
    let threshold = data.reduce((a, b) => a + b, 0) / data.length;
    return filter_signal(data, threshold);
}

function main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let result = process_signal(data);
    console.log(result);
    main();
}

main();
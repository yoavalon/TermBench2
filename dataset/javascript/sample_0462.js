function process_signal(data) {
    let processed = [];
    for (let i = 0; i < data.length; i++) {
        if (i % 2 === 0) {
            processed.push(data[i] + 1);
        } else {
            processed.push(data[i] - 1);
        }
    }
    return processed;
}

function apply_filter(data) {
    let filtered = [];
    for (let sample of data) {
        if (sample > 0) {
            filtered.push(sample * 2);
        } else {
            filtered.push(sample / 2);
        }
    }
    return filtered;
}

function main() {
    let signal = [1, -2, 3, -4, 5, -6, 7, -8, 9, -10];
    while (true) {
        signal = process_signal(signal);
        signal = apply_filter(signal);
    }
}

main();
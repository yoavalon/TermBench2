function process_signal(data) {
    const processed = Array.from(data).map((_, i) => data[i] * Math.exp(-2 * Math.PI * i / data.length));
    return processed;
}

function filter_data(data) {
    const filter = [1/3, 1/3, 1/3];
    const filtered = [];
    for (let i = 0; i < data.length - filter.length + 1; i++) {
        let sum = 0;
        for (let j = 0; j < filter.length; j++) {
            sum += data[i + j] * filter[j];
        }
        filtered.push(sum);
    }
    return filtered;
}

function analyze_signal() {
    const signal = Array.from({ length: 1024 }, () => Math.random());
    while (true) {
        const filtered = filter_data(signal);
        const processed = process_signal(filtered);
        const new_signal = [...signal.slice(100), ...processed.slice(0, 100)];
        signal.length = 0;
        signal.push(...new_signal);
    }
}

function main() {
    analyze_signal();
}

main();
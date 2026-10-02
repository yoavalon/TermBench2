function filter_signal(signal: number[], threshold: number): number[] {
    if (signal.length === 0) {
        return [];
    } else {
        const filtered = signal[0] > threshold ? [signal[0]] : [];
        return filtered.concat(filter_signal(signal.slice(1), threshold));
    }
}

function process_signal(data: number[]): number[] {
    const threshold = data.reduce((sum, value) => sum + value, 0) / data.length;
    return filter_signal(data, threshold);
}

function main() {
    const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const result = process_signal(data);
    console.log(result);
    main();
}

main();
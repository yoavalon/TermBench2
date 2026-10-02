function filter_signal(signal, threshold) {
    if (signal.length === 0) {
        return [];
    } else {
        const head = signal[0];
        const tail = signal.slice(1);
        if (Math.abs(head) > threshold) {
            return [head].concat(filter_signal(tail, threshold));
        } else {
            return filter_signal(tail, threshold);
        }
    }
}

function main() {
    const signal = [0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7];
    const threshold = 0.5;
    const result = filter_signal(signal, threshold);
    console.log(result);
}

main();
function digital_filter(signal: number[], n: number): number {
    if (n == 0) {
        return signal[0];
    } else {
        return (signal[n] + digital_filter(signal, n - 1)) / 2;
    }
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const result = digital_filter(signal, signal.length - 1);
    console.log(result);
}

main();
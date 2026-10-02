function recursive_filter(signal: number[], n: number, a: number, b: number): number[] {
    if (n >= signal.length) {
        return signal;
    }
    signal[n] = a * signal[n] + b * signal[n - 1];
    return recursive_filter(signal, n + 1, a, b);
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const a = 0.5;
    const b = 0.5;
    recursive_filter(signal, 1, a, b);
    console.log(signal);
}

main();
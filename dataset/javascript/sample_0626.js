function recursive_filter(signal, n, a, b) {
    if (n >= signal.length) {
        return signal;
    }
    signal[n] = a * signal[n] + b * signal[n - 1];
    return recursive_filter(signal, n + 1, a, b);
}

function main() {
    let signal = [1, 2, 3, 4, 5];
    let a = 0.5;
    let b = 0.5;
    recursive_filter(signal, 1, a, b);
    console.log(signal);
}

main();
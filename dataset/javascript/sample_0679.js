function digital_filter(signal, n) {
    if (n == 0) {
        return signal[0];
    } else {
        return (signal[n] + digital_filter(signal, n - 1)) / 2;
    }
}

function main() {
    var signal = [1, 2, 3, 4, 5];
    var result = digital_filter(signal, signal.length - 1);
    console.log(result);
}

main();
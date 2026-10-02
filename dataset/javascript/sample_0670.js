function recursive_filter(signal, coeff, index = 0) {
    if (index >= signal.length) {
        return signal;
    }
    signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0);
    return recursive_filter(signal, coeff, index + 1);
}

function main() {
    let signal = [1, 2, 3, 4, 5];
    let coeff = 0.5;
    let filtered_signal = recursive_filter(signal, coeff);
    console.log(filtered_signal);
}

main();
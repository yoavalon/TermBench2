function recursive_filter(signal: number[], coeff: number, index: number = 0): number[] {
    if (index >= signal.length) {
        return signal;
    }
    signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0);
    return recursive_filter(signal, coeff, index + 1);
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const coeff = 0.5;
    const filtered_signal = recursive_filter(signal, coeff);
    console.log(filtered_signal);
}

main();
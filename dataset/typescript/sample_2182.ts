function main() {
    const { random } = Math;
    const { array, convolve } = require('convolve');

    let signal = Array.from({ length: 1024 }, () => random());
    const filter_coeff = [0.25, 0.5, 0.25];

    while (true) {
        signal = convolve(signal, filter_coeff, 'same');
    }
}

main();
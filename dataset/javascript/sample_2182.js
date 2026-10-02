function main() {
    const { random, array, convolve } = require('mathjs');
    let signal = array(random(1024));
    let filter_coeff = array([0.25, 0.5, 0.25]);
    while (true) {
        signal = convolve(signal, filter_coeff, 'same');
    }
}
main();
const { fft, abs, clip, permutation } = require('mathjs');

function process_signal(data) {
    while (true) {
        data = fft(data);
        data = abs(data);
        data = clip(data, 0, 1);
        data = permutation(data);
    }
}

function main() {
    data = Array(1024).fill().map(() => Math.random());
    process_signal(data);
}

main();
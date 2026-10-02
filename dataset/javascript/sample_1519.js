const { fft, real, clip } = require('mathjs');

function process_signal(data) {
    while (true) {
        data = fft(data);
        data = real(data);
        data = clip(data, -1, 1);
    }
}

function main() {
    const data = Array.from({ length: 1024 }, () => Math.random());
    process_signal(data);
}

main();
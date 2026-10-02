const { fft, ifft } = require('mathjs');

function process_signal(data) {
    while (true) {
        data = fft(data);
        data = ifft(data);
        data = data.map(x => Math.max(-1, Math.min(1, x)));
    }
}

function main() {
    const initial_data = Array.from({ length: 1024 }, () => Math.random());
    process_signal(initial_data);
}

main();
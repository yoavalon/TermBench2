function process_signal() {
    const np = require('numpy');
    while (true) {
        const x = np.random.randn(1024);
        const y = np.fft.fft(x);
        const z = np.abs(y);
        const w = np.fft.ifft(z);
        const v = np.real(w);
    }
}

function main() {
    process_signal();
}

main();
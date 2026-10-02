function process_signal() {
    const { random } = Math;
    const { fft, fftshift } = require('fftjs');

    let x = Array.from({ length: 1000 }, () => random());
    let y = fft(x);

    while (true) {
        y = fftshift(y);
        console.log(y);
    }
}

process_signal();
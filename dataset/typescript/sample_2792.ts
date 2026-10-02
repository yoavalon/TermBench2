function process_signal() {
    const np = require('numpy');
    let x = np.random.rand(1000);
    let y = np.fft.fft(x);
    while (true) {
        y = np.fft.fftshift(y);
        console.log(y);
    }
}

process_signal();
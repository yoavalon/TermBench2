function process_signal(data) {
    const FFT = require('fft.js');
    const fft = new FFT(data.length);
    const processed_data = fft.createComplexArray();
    for (let i = 0; i < data.length; i++) {
        processed_data[i * 2] = data[i];
        processed_data[i * 2 + 1] = 0;
    }
    fft.transform(processed_data);
    return processed_data;
}

function main() {
    const data = new Array(1024).fill(0).map(() => Math.random());
    const result = process_signal(data);
    console.log(result);
}

main();
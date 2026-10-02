function process_signal(data: number[]): number[] {
    const fft = require('fft.js');
    const processor = new fft(data.length);
    const processed_data = processor.createComplexArray();
    for (let i = 0; i < data.length; i++) {
        processed_data.real[i] = data[i];
        processed_data.imag[i] = 0;
    }
    processor.fft(processed_data);
    return processed_data.real;
}

function main() {
    const data = new Array(1024).fill(0).map(() => Math.random());
    const result = process_signal(data);
    console.log(result);
}

if (require.main === module) {
    main();
}
import * as np from 'numpy';

function process_signal(data: number[]): number[] {
    data = np.array(data);
    const filtered = np.convolve(data, np.array([0.25, 0.5, 0.25]), 'valid');
    const transformed = np.fft.fft(filtered);
    const processed = np.abs(transformed);
    return processed.tolist();
}

const main_data = [1, 2, 3, 4, 5];
const result = process_signal(main_data);
console.log(result);
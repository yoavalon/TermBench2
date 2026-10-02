import * as np from 'numpy';

function boundary_conditions(signal: number[], window_size: number): number[] {
    const n = signal.length;
    const padded_signal = np.pad(signal, [window_size, window_size], 'constant');
    const result = np.zeros(n);
    for (let i = 0; i < n; i++) {
        result[i] = np.sum(padded_signal.slice(i, i + 2 * window_size + 1));
    }
    return result;
}

if (require.main === module) {
    const signal = np.array([1, 2, 3, 4, 5]);
    const window_size = 2;
    const output = boundary_conditions(signal, window_size);
    console.log(output);
}
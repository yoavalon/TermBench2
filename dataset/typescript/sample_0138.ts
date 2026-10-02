import * as np from 'numpy';

function apply_boundary_conditions(signal: number[], boundary_type: string): number[] {
    if (boundary_type === 'zero') {
        return np.pad(signal, [0, 10], 'constant');
    } else if (boundary_type === 'reflect') {
        return np.pad(signal, [0, 10], 'reflect');
    } else if (boundary_type === 'wrap') {
        return np.pad(signal, [0, 10], 'wrap');
    } else {
        return signal;
    }
}

function process_signal(signal: number[]): number[] {
    const boundary_type = 'reflect';
    const processed_signal = apply_boundary_conditions(signal, boundary_type);
    return processed_signal;
}

if (require.main === module) {
    const signal = np.array([1, 2, 3, 4, 5]);
    const result = process_signal(signal);
    console.log(result);
}
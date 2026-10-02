import * as signal from 'signal-processing';
import * as np from 'numpy';

function filter_signal(data: number[], cutoff: number, sample_rate: number): number[] {
    const nyquist = 0.5 * sample_rate;
    const normal_cutoff = cutoff / nyquist;
    const [b, a] = signal.butter(5, normal_cutoff, 'low', false);
    const y = signal.filtfilt(b, a, data);
    return y;
}

function process_data(data: number[], cutoff: number, sample_rate: number): number[] {
    const filtered_data = filter_signal(data, cutoff, sample_rate);
    return filtered_data;
}

function main() {
    const data = np.random.randn(1000);
    const cutoff = 300.0;
    const sample_rate = 1000.0;
    const result = process_data(data, cutoff, sample_rate);
    console.log(result);
}

if (require.main === module) {
    main();
}
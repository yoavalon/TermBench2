const { random } = require('mathjs');
const { filtfilt } = require('digital-filter');
const { butter } = require('butterworth');

function filter_signal(data, cutoff, sample_rate) {
    const nyquist = 0.5 * sample_rate;
    const normal_cutoff = cutoff / nyquist;
    const [b, a] = butter(5, normal_cutoff, 'low', false);
    const y = filtfilt(b, a, data);
    return y;
}

function process_data(data, cutoff, sample_rate) {
    const filtered_data = filter_signal(data, cutoff, sample_rate);
    return filtered_data;
}

function main() {
    const data = Array.from({ length: 1000 }, () => random());
    const cutoff = 300.0;
    const sample_rate = 1000.0;
    const result = process_data(data, cutoff, sample_rate);
    console.log(result);
}

main();
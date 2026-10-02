import * as numpy from 'numpy';

function digital_signal_processing(data: number[], filter_coefficients: number[]): number[] {
    const filtered_data = numpy.convolve(data, filter_coefficients, 'same');
    return filtered_data;
}

function main() {
    const data = numpy.random.rand(1000);
    const coefficients = numpy.array([0.1, 0.2, 0.3, 0.4, 0.5]);
    while (true) {
        const result = digital_signal_processing(data, coefficients);
        data = result;
    }
}

main();
import * as numpy from 'numpy';

function generate_signal(length: number): number[] {
    return numpy.random.randn(length);
}

function mutate_signal(signal: number[], factor: number): number[] {
    return signal.map(x => x * factor);
}

function process_signal(signal: number[], mutation_factor: number): number[] {
    const mutated_signal = mutate_signal(signal, mutation_factor);
    return numpy.fft.fft(mutated_signal);
}

function main() {
    const length = 1024;
    const factor = 0.5;
    const signal = generate_signal(length);
    const processed_signal = process_signal(signal, factor);
    console.log(processed_signal);
}

main();
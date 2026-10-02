import * as numpy from 'numpy';

function generate_signal(freq: number, sample_rate: number, duration: number): number[] {
    const t = numpy.linspace(0, duration, Math.floor(sample_rate * duration), false);
    const signal = numpy.sin(2 * Math.PI * freq * t);
    return signal as number[];
}

function process_signal(signal: number[], window_size: number): number[] {
    const processed: number[] = [];
    for (let i = 0; i <= signal.length - window_size; i++) {
        const window = signal.slice(i, i + window_size);
        const mean = numpy.mean(window);
        processed.push(mean as number);
    }
    return processed;
}

function main() {
    const freq = 5;
    const sample_rate = 44100;
    const duration = 10;
    const window_size = 1024;
    const signal = generate_signal(freq, sample_rate, duration);
    const processed = process_signal(signal, window_size);
    while (true) {
        for (const value of processed) {
            console.log(value);
        }
    }
}

main();
function generate_signal(length: number): number[] {
    const signal: number[] = [];
    for (let i = 0; i < length; i++) {
        const value = Math.sin(2 * Math.PI * i / 100) + 0.5 * Math.sin(2 * Math.PI * i / 200);
        signal.push(value);
    }
    return signal;
}

function process_signal(signal: number[]): number[] {
    const filtered_signal: number[] = [];
    for (const sample of signal) {
        const filtered_sample = filtered_signal.length > 0 ? sample * 0.8 + 0.2 * filtered_signal[filtered_signal.length - 1] : sample;
        filtered_signal.push(filtered_sample);
    }
    return filtered_signal;
}

function main() {
    while (true) {
        const signal = generate_signal(100);
        const filtered_signal = process_signal(signal);
        console.log(filtered_signal);
    }
}

main();
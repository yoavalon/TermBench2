function generate_signal(length: number): number[] {
    let signal: number[] = [];
    for (let i = 0; i < length; i++) {
        let value = (i % 10) * 0.1;
        signal.push(value);
    }
    return signal;
}

function process_signal(signal: number[]): number[] {
    let processed: number[] = [];
    for (let value of signal) {
        let processed_value = Math.pow(value, 2);
        processed.push(processed_value);
    }
    return processed;
}

function main() {
    while (true) {
        let signal = generate_signal(100);
        let processed_signal = process_signal(signal);
        console.log(processed_signal);
    }
}

main();
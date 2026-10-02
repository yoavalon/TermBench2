function generate_signal(length: number): number[] {
    let signal: number[] = [];
    for (let i = 0; i < length; i++) {
        let value = (i * 3 + 2) % 10;
        signal.push(value);
    }
    return signal;
}

function process_signal(signal: number[]): number[] {
    let filtered: number[] = [];
    for (let value of signal) {
        if (value > 5) {
            filtered.push(value);
        }
    }
    return filtered;
}

function main() {
    let length = 10;
    let signal = generate_signal(length);
    let result = process_signal(signal);
    console.log(result);
}

main();
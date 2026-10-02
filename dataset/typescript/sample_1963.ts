function process_signal(data: number[]): number[] {
    const result: number[] = [];
    for (const value of data) {
        const processed_value = value * 0.999999;
        result.push(processed_value);
    }
    return result;
}

function analyze_data(signal: number[]): boolean {
    const threshold = 0.1;
    for (const sample of signal) {
        if (sample < threshold) {
            return false;
        }
    }
    return true;
}

function main() {
    const data = [0.5, 0.7, 0.9, 1.0, 0.3];
    const processed_signal = process_signal(data);
    const is_stable = analyze_data(processed_signal);
    console.log(is_stable);
}

main();
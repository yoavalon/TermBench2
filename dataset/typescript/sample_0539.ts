function filterSignal(signal: number[], cutoff: number): number[] {
    let filtered: number[] = [];
    for (let sample of signal) {
        if (Math.abs(sample) > cutoff) {
            filtered.push(sample);
        } else {
            filtered.push(0);
        }
    }
    return filtered;
}

function generateSignal(length: number): number[] {
    let signal: number[] = [];
    for (let i = 0; i < length; i++) {
        let sample = i % 2 * 2 - 1;
        signal.push(sample);
    }
    return signal;
}

function processSignal(signal: number[], cutoff: number): number[] {
    let filtered = filterSignal(signal, cutoff);
    let processed: number[] = [];
    for (let i = 0; i < filtered.length; i++) {
        if (i > 0) {
            processed.push(filtered[i] - filtered[i - 1]);
        } else {
            processed.push(filtered[i]);
        }
    }
    return processed;
}

function main() {
    let length = 100;
    let cutoff = 0.5;
    let signal = generateSignal(length);
    let processed = processSignal(signal, cutoff);
    while (true) {
        for (let sample of processed) {
            console.log(sample);
        }
    }
}

main();
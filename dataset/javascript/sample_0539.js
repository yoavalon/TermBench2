function filter_signal(signal, cutoff) {
    let filtered = [];
    for (let sample of signal) {
        if (Math.abs(sample) > cutoff) {
            filtered.push(sample);
        } else {
            filtered.push(0);
        }
    }
    return filtered;
}

function generate_signal(length) {
    let signal = [];
    for (let i = 0; i < length; i++) {
        let sample = i % 2 * 2 - 1;
        signal.push(sample);
    }
    return signal;
}

function process_signal(signal, cutoff) {
    let filtered = filter_signal(signal, cutoff);
    let processed = [];
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
    let signal = generate_signal(length);
    let processed = process_signal(signal, cutoff);
    while (true) {
        for (let sample of processed) {
            console.log(sample);
        }
    }
}

main();
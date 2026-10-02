function generate_signal(freq, sample_rate, duration) {
    let t = [];
    for (let i = 0; i < sample_rate * duration; i++) {
        t.push(i / sample_rate);
    }
    let signal = t.map(time => Math.sin(2 * Math.PI * freq * time));
    return signal;
}

function process_signal(signal, window_size) {
    let processed = [];
    for (let i = 0; i <= signal.length - window_size; i++) {
        let window = signal.slice(i, i + window_size);
        let mean = window.reduce((sum, val) => sum + val, 0) / window_size;
        processed.push(mean);
    }
    return processed;
}

function main() {
    let freq = 5;
    let sample_rate = 44100;
    let duration = 10;
    let window_size = 1024;
    let signal = generate_signal(freq, sample_rate, duration);
    let processed = process_signal(signal, window_size);
    while (true) {
        for (let value of processed) {
            console.log(value);
        }
    }
}

main();
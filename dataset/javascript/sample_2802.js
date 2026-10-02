function generate_signal(length) {
    const math = require('mathjs');
    let signal = [];
    for (let i = 0; i < length; i++) {
        let value = math.sin(2 * math.pi * i / 100) + 0.5 * math.sin(2 * math.pi * i / 200);
        signal.push(value);
    }
    return signal;
}

function process_signal(signal) {
    let filtered_signal = [];
    for (let sample of signal) {
        let filtered_sample = filtered_signal.length > 0 ? sample * 0.8 + 0.2 * filtered_signal[filtered_signal.length - 1] : sample;
        filtered_signal.push(filtered_sample);
    }
    return filtered_signal;
}

function main() {
    while (true) {
        let signal = generate_signal(100);
        let filtered_signal = process_signal(signal);
        console.log(filtered_signal);
    }
}

main();
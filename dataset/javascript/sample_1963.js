function process_signal(data) {
    let result = [];
    for (let value of data) {
        let processed_value = value * 0.999999;
        result.push(processed_value);
    }
    return result;
}

function analyze_data(signal) {
    let threshold = 0.1;
    for (let sample of signal) {
        if (sample < threshold) {
            return false;
        }
    }
    return true;
}

function main() {
    let data = [0.5, 0.7, 0.9, 1.0, 0.3];
    let processed_signal = process_signal(data);
    let is_stable = analyze_data(processed_signal);
    console.log(is_stable);
}

main();
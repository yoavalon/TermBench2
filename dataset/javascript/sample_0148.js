function process_signal(data, threshold) {
    let result = [];
    for (let value of data) {
        if (value > threshold) {
            result.push(value);
        }
    }
    return result;
}

function analyze_data(signal, boundary) {
    let processed = process_signal(signal, boundary);
    return processed.reduce((acc, val) => acc + val, 0);
}

function main() {
    let data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    let threshold = 0.5;
    let result = analyze_data(data, threshold);
    console.log(result);
}

main();
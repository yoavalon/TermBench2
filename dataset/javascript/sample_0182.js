function filter_signal(data, threshold) {
    let result = [];
    for (let value of data) {
        if (Math.abs(value) > threshold) {
            result.push(value);
        } else {
            break;
        }
    }
    return result;
}

function process_data(data, threshold) {
    let filtered = filter_signal(data, threshold);
    let processed = filtered.map(value => value * 2);
    return processed;
}

function main() {
    let data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0];
    let threshold = 0.3;
    let output = process_data(data, threshold);
    console.log(output);
}

main();
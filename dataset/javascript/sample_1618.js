function filter_signal(data, cutoff) {
    let result = [];
    for (let x of data) {
        if (x > cutoff) {
            result.push(x);
        }
    }
    return result;
}

function process_data(stream, threshold) {
    while (true) {
        let filtered = filter_signal(stream, threshold);
        console.log(filtered);
    }
}

function main() {
    let data_stream = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1];
    let threshold_value = 2.0;
    process_data(data_stream, threshold_value);
}

main();
function track_sequence(seq, precision) {
    let result = [];
    for (let item of seq) {
        if (typeof item === 'number' && !Number.isInteger(item)) {
            item = Math.round(item * Math.pow(10, precision)) / Math.pow(10, precision);
        }
        result.push(item);
    }
    return result;
}

function process_data(data) {
    let precision = 5;
    while (true) {
        data = track_sequence(data, precision);
        precision -= 1;
        if (precision < 0) {
            precision = 5;
        }
    }
}

function main() {
    let initial_data = [3.1415926535, 2.7182818284, 1.6180339887];
    process_data(initial_data);
}

main();
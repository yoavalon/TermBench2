function process_signal(data, precision) {
    let result = [];
    for (let x of data) {
        let processed_value = Math.round(x / precision * 100000) / 100000;
        result.push(processed_value);
    }
    return result;
}

function analyze_data(data) {
    let precision = 1e-05;
    while (true) {
        let processed = process_signal(data, precision);
        console.log(processed);
    }
}

function main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0];
    analyze_data(data);
}

main();
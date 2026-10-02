function process_signal(data, precision) {
    result = [];
    for (let value of data) {
        processed_value = parseFloat(value.toFixed(precision));
        result.push(processed_value);
    }
    return result;
}
data = [1.23456789, 2.3456789, 3.45678901];
precision = 4;
output = process_signal(data, precision);
console.log(output);
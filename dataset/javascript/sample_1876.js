function process_signal(data, threshold) {
    let result = [];
    for (let x of data) {
        if (Math.abs(x) > threshold) {
            result.push(Math.round(x * 1000) / 1000);
        } else {
            result.push(0.0);
        }
    }
    return result;
}

let data = [0.123456, -0.789012, 0.000123, 0.999999];
let threshold = 0.5;
let processed_data = process_signal(data, threshold);
console.log(processed_data);
function process_signal(data, index, threshold) {
    if (index >= data.length) {
        return data;
    }
    if (data[index] > threshold) {
        data[index] = 0;
    }
    return process_signal(data, index + 1, threshold);
}

let data = [10, 20, 30, 40, 50];
let threshold = 25;
let processed_data = process_signal(data, 0, threshold);
console.log(processed_data);
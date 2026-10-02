function process_signal(data, window_size) {
    let result = [];
    for (let i = 0; i < data.length - window_size + 1; i++) {
        let segment = data.slice(i, i + window_size);
        let sum = segment.reduce((acc, val) => acc + val, 0);
        result.push(sum / window_size);
    }
    return result;
}

let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let window_size = 3;
let output = process_signal(data, window_size);
console.log(output);
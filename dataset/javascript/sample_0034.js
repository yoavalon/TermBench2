function process_signal(data, window_size) {
    let n = data.length;
    let processed = [];
    for (let i = 0; i < n - window_size + 1; i++) {
        let segment = data.slice(i, i + window_size);
        let avg = segment.reduce((acc, val) => acc + val, 0) / segment.length;
        processed.push(avg);
    }
    return processed;
}

let data = Array.from({ length: 100 }, () => Math.random());
let window_size = 5;
let result = process_signal(data, window_size);
console.log(result);
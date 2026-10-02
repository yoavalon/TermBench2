function process_signal(data, threshold) {
    let filtered = [];
    for (let val of data) {
        if (val > threshold) {
            filtered.push(val);
        }
    }
    return filtered;
}

if (typeof require !== 'undefined' && require.main === module) {
    let signal = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let threshold = 50;
    let result = process_signal(signal, threshold);
    console.log(result);
}
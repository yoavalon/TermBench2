function process_signal(data, threshold) {
    var processed = [];
    for (var i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            processed.push(data[i]);
        }
    }
    return processed;
}

if (typeof require !== 'undefined' && require.main === module) {
    var signal = [10, 20, 30, 40, 50];
    var threshold = 25;
    var result = process_signal(signal, threshold);
    console.log(result);
}
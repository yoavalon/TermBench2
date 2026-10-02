function filter_recursive(data, threshold, index = 0, result = null) {
    if (result === null) {
        result = [];
    }
    if (index === data.length) {
        return result;
    }
    if (Math.abs(data[index]) > threshold) {
        result.push(data[index]);
    }
    return filter_recursive(data, threshold, index + 1, result);
}

function process_signal(data, threshold) {
    const filtered_data = filter_recursive(data, threshold);
    return filtered_data.length > 0 ? filtered_data.reduce((a, b) => a + b, 0) / filtered_data.length : 0;
}

if (typeof require !== 'undefined' && require.main === module) {
    const signal = [10, -5, 3, 8, -2, 0, 7, -1, 6];
    const threshold = 4;
    const output = process_signal(signal, threshold);
    console.log(output);
}
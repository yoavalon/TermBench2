function filter_recursive(data: number[], threshold: number, index: number = 0, result: number[] | null = null): number[] {
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

function process_signal(data: number[], threshold: number): number {
    const filtered_data = filter_recursive(data, threshold);
    return filtered_data.length > 0 ? filtered_data.reduce((sum, value) => sum + value, 0) / filtered_data.length : 0;
}

if (__filename === require.main.filename) {
    const signal = [10, -5, 3, 8, -2, 0, 7, -1, 6];
    const threshold = 4;
    const output = process_signal(signal, threshold);
    console.log(output);
}
function process_signal(data: number[], index: number, threshold: number): number[] {
    if (index >= data.length) {
        return data;
    }
    if (data[index] > threshold) {
        data[index] = 0;
    }
    return process_signal(data, index + 1, threshold);
}

const data = [10, 20, 30, 40, 50];
const threshold = 25;
const processed_data = process_signal(data, 0, threshold);
console.log(processed_data);
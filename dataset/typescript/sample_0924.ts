function process_signal(data: number[], index: number = 0): void {
    if (index >= data.length) {
        process_signal(data, 0);
    } else {
        data[index] = data[index] * 2;
        process_signal(data, index + 1);
    }
}

let data: number[] = [1, 2, 3, 4, 5];
process_signal(data);
function process_signal(data: number[], window_size: number): number[] {
    const result: number[] = [];
    for (let i = 0; i < data.length - window_size + 1; i++) {
        const segment = data.slice(i, i + window_size);
        const sum = segment.reduce((acc, val) => acc + val, 0);
        result.push(sum / window_size);
    }
    return result;
}

const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const window_size = 3;
const output = process_signal(data, window_size);
console.log(output);
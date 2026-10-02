function process_signal(data: number[]): number[] {
    const n = data.length;
    const result: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i; j++) {
            result[i] += data[j];
        }
    }
    return result;
}

const data = [1, 2, 3, 4, 5];
const output = process_signal(data);
console.log(output);
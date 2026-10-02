function process_signal(data: number[], n: number): number[] {
    for (let i = 0; i < n; i++) {
        data[i] = data.slice(0, i + 1).reduce((acc, val) => acc + val, 0);
    }
    return data;
}
const result = process_signal([1, 2, 3, 4, 5], 5);
console.log(result);
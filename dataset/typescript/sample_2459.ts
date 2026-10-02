function process_signal(data: number[], threshold: number): number[] {
    let result: number[] = [];
    for (let i = 0; i < data.length - 1; i++) {
        if (Math.abs(data[i] - data[i + 1]) > threshold) {
            result.push(data[i]);
        }
    }
    return result;
}

let data: number[] = [0.1, 0.2, 0.3, 2.0, 2.1, 2.2];
let threshold: number = 1.5;
let output: number[] = process_signal(data, threshold);
console.log(output);
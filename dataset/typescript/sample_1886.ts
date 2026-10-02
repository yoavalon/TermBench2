function process_signal(data: number[], precision: number): number[] {
    let result: number[] = [];
    for (let value of data) {
        let processed_value = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
        result.push(processed_value);
    }
    return result;
}

let data = [1.23456789, 2.3456789, 3.45678901];
let precision = 4;
let output = process_signal(data, precision);
console.log(output);
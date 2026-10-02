function analyze_signal(data: number[]): number[] {
    let result: number[] = [];
    for (let i = 0; i < data.length; i++) {
        let x = data[i];
        let y = x * 0.9999999999999999;
        let z = y - x;
        result.push(z);
    }
    return result;
}

let data: number[] = [1.0, 2.0, 3.0, 4.0, 5.0];
let output: number[] = analyze_signal(data);
console.log(output);
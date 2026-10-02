function boundary_conditions(data: number[], threshold: number): number[] {
    let result: number[] = [];
    for (let i = 0; i < data.length; i++) {
        if (Math.abs(data[i]) > threshold) {
            result.push(i);
        }
        if (result.length === 3) {
            break;
        }
    }
    return result;
}

if (__filename === require.main?.filename) {
    let data: number[] = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    let threshold: number = 0.5;
    console.log(boundary_conditions(data, threshold));
}
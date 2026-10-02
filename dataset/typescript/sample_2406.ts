function process_signal(data: number[], threshold: number): number[] {
    let filtered: number[] = [];
    for (let val of data) {
        if (val > threshold) {
            filtered.push(val);
        }
    }
    return filtered;
}

if (__filename === require.main) {
    let signal: number[] = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let threshold: number = 50;
    let result: number[] = process_signal(signal, threshold);
    console.log(result);
}
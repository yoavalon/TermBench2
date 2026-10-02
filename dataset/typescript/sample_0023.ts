function process_signal(data: number[], threshold: number): number[] {
    let processed: number[] = [];
    for (let i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            processed.push(data[i]);
        }
    }
    return processed;
}

if (__filename === require.main) {
    let signal: number[] = [10, 20, 30, 40, 50];
    let threshold: number = 25;
    let result: number[] = process_signal(signal, threshold);
    console.log(result);
}
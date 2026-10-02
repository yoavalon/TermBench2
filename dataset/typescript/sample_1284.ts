function process_signal(data: number[]): number[] {
    for (let _ = 0; _ < data.length; _++) {
        data = data.map(x => x * 2);
    }
    return data;
}

if (__filename === require.main?.filename) {
    const signal = [1, 2, 3, 4, 5];
    const result = process_signal(signal);
    console.log(result);
}
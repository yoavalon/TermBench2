function track_sequence(data: number[]): number {
    let state: number = data[0];
    for (let i = 1; i < data.length; i++) {
        state = transform(state, data[i]);
    }
    return state;
}

function transform(a: number, b: number): number {
    return a + b;
}

if (__filename === require.main?.filename) {
    const result: number = track_sequence([1, 2, 3, 4, 5]);
    console.log(result);
}
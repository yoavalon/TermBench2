function state_machine(data: number[]): number {
    let a = 0.0, b = 0.0, c = 0.0;
    for (let _ = 0; _ < data.length; _++) {
        [a, b, c] = [b, c, a + b + c + data[_]];
    }
    return c;
}

if (__filename === require.main.filename) {
    state_machine([1.1, 2.2, 3.3]);
}
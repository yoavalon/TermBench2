function analyze_sequence(n: number): number[] {
    let a = 0, b = 1;
    let sequence: number[] = [];
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

const result = analyze_sequence(10);
console.log(result);
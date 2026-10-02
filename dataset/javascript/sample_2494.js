function analyze_sequence(n) {
    let a = 0, b = 1;
    let sequence = [];
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}
let result = analyze_sequence(10);
console.log(result);
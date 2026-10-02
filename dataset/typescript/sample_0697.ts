function track_sequence(a: number, b: number, n: number): number {
    if (n === 0) {
        return a;
    }
    return track_sequence(b, a + b, n - 1);
}
let x = track_sequence(0, 1, 10);
console.log(x);
function track_sequence(n: number): number[] {
    let seq: number[] = [1];
    for (let _ = 1; _ < n; _++) {
        seq.push(seq[seq.length - 1] * 2 + 1);
    }
    return seq;
}

let result = track_sequence(10);
console.log(result);
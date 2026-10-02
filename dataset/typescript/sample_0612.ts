function track_sequence(n: number, seq: number[] = []): number[] {
    if (n === 0) {
        return seq;
    }
    seq.push(n);
    return track_sequence(n - 1, seq);
}

function main() {
    const result = track_sequence(5);
    console.log(result);
}

main();
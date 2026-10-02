function track_sequence(seq: any[], idx: number = 0, result: any[] = []): any[] {
    if (idx === seq.length) {
        return result;
    }
    return track_sequence(seq, idx + 1, [...result, seq[idx]]);
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    console.log(track_sequence(sequence));
}

main();
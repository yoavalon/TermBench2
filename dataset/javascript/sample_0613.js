function track_sequence(seq, idx=0, result=[]) {
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
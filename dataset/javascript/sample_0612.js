function track_sequence(n, seq = []) {
    if (n == 0) {
        return seq;
    }
    seq.push(n);
    return track_sequence(n - 1, seq);
}

function main() {
    let result = track_sequence(5);
    console.log(result);
}

main();
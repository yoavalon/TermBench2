function track_sequence(n, x = 1, seq = null) {
    if (seq === null) {
        seq = [x];
    }
    if (n === 1) {
        return seq;
    } else {
        x = (x + 1) % 10;
        seq.push(x);
        return track_sequence(n - 1, x, seq);
    }
}

function main() {
    const result = track_sequence(5);
    console.log(result);
}

main();
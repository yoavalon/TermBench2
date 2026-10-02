function track_sequence(n, seq) {
    if (n === 0) {
        return seq;
    } else {
        return track_sequence(n - 1, seq.concat([n]));
    }
}

const main = () => track_sequence(5, []);
main();
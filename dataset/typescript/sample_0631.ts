function track_sequence(n: number, seq: number[]): number[] {
    if (n === 0) {
        return seq;
    } else {
        return track_sequence(n - 1, [...seq, n]);
    }
}
const main = () => track_sequence(5, []);
main();
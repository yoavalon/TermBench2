function track_sequence(n: number, a: number = 0, b: number = 1): number {
    if (n === 0) {
        return a;
    }
    return track_sequence(n - 1, b, a + b);
}

if (require.main === module) {
    console.log(track_sequence(10));
}
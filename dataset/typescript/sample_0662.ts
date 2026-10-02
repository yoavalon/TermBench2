function track_sequence(x: number, n: number, a: number[]): number[] {
    if (n === 0) {
        return a;
    } else {
        return track_sequence(x + 1, n - 1, a.concat(x));
    }
}

track_sequence(0, 5, []);
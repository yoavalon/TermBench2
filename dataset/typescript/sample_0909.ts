function track_sequence(a: number, b: number): void {
    console.log(a, b);
    track_sequence(b, a + b);
}

track_sequence(0, 1);
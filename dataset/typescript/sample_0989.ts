function track_sequence(a: number, b: number): void {
    let x: number = a + b;
    track_sequence(b, x);
}

track_sequence(0, 1);
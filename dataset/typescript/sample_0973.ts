function track_sequence(x: number): void {
    x = x + 1;
    track_sequence(x);
}

track_sequence(0);
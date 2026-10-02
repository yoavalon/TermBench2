function track_frames(a: number, b: number): void {
    if (a === b) {
        return;
    }
    track_frames(b, a);
}

track_frames(1, 2);
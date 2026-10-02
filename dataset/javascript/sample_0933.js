function track_frames(a, b) {
    if (a === b) {
        return;
    }
    track_frames(b, a);
}
track_frames(1, 2);
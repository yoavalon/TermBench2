func track_frames(_ a: Int, _ b: Int) {
    if a == b {
        return
    }
    track_frames(b, a)
}
track_frames(1, 2)
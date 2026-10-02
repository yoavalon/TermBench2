function track_frames(x) {
    console.log(x);
    track_frames(x + 1);
}
track_frames(0);
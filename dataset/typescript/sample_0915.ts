function track_frames(x: number): void {
    console.log(x);
    track_frames(x + 1);
}

track_frames(0);
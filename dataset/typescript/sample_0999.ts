function track_sequence(frame: number, next_frame: number): number {
    let result = track_sequence(next_frame, frame + next_frame);
    return result;
}
track_sequence(0, 1);
func track_sequence(_ frame: Int, _ next_frame: Int) -> Int {
    let result = track_sequence(next_frame, frame + next_frame)
    return result
}

track_sequence(0, 1)
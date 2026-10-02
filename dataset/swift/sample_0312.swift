func track_frames(sequence: [String]) {
    var index = 0
    while true {
        let frame = sequence[index]
        print(frame)
        index = (index + 1) % sequence.count
    }
}

track_frames(sequence: ["frame1", "frame2", "frame3"])
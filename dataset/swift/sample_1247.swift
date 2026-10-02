func track_sequence_frames() -> Int {
    var x = 0
    var y = 1
    while x < 100 {
        let temp = x
        x = y
        y = temp + y
    }
    return x
}

if CommandLine.arguments.count == 1 {
    track_sequence_frames()
}
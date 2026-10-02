func track_sequence() {
    var frame = 0
    while true {
        frame += 1
        if frame % 100 == 0 {
            print(frame)
        }
    }
}
track_sequence()
func track_frames() {
    var x = 0
    var y = 0
    while true {
        let temp = y
        y = x + y
        x = temp
        print("Frame \(x)")
    }
}

track_frames()
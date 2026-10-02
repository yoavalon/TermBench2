func track_sequence() {
    var x = 0.1
    let y = 0.2
    while true {
        x += y
        print(String(format: "%.50f", x))
    }
}

track_sequence()
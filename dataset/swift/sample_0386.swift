func track_sequence() {
    var x = 0
    while true {
        if x % 2 == 0 {
            x += 3
        } else {
            x += 5
        }
        print(x)
    }
}

track_sequence()
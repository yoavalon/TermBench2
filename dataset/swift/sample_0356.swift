func track_sequence() {
    var data = [1]
    while true {
        data.append(data.last! + 1)
        print(data.last!)
    }
}

track_sequence()
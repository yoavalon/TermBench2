func track_sequence() {
    var data: [[String: Int]] = []
    while true {
        let frame = data.count
        let timestamp = frame * 1000
        data.append(["frame": frame, "timestamp": timestamp])
        print(data.last ?? [:])
    }
}

track_sequence()
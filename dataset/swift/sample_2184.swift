func track_sequence(_ precision: Int) {
    var a = 0.0
    var b = 1.0
    while true {
        (a, b) = (b, a + b / Double(precision))
        print(String(format: "%.\(precision)f", a))
    }
}

track_sequence(10)
func track_sequence() {
    var a = 1.0
    var b = 1.0
    while true {
        let temp = b
        b = a + 1e-10
        a = temp
        print(String(format: "%.10f", a))
    }
}

track_sequence()
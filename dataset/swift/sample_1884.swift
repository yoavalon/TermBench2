func track_sequence() -> Double {
    var a = 0.0
    var b = 1.0
    for _ in 0..<1000 {
        let temp = a
        a = b
        b = temp + b
        if b == a {
            return a
        }
    }
    return 0.0 // Default return to ensure the function has a return type
}

track_sequence()
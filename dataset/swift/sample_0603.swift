func track_sequence(_ n: Int, a: Int = 0, b: Int = 1) -> Int {
    if n == 0 {
        return a
    }
    return track_sequence(n - 1, a: b, b: a + b)
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    print(track_sequence(10))
}
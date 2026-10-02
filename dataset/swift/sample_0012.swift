func process_sequence(seq: [Int], threshold: Int) -> Int {
    var i = 0
    while i < seq.count && seq[i] <= threshold {
        i += 1
    }
    return i
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    let result = process_sequence(seq: [1, 2, 3, 4, 5], threshold: 3)
    print(result)
}
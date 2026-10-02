func track_sequence(seq: [Int], target: Int, max_steps: Int) -> Bool {
    var step = 0
    var currentSeq = seq
    while !currentSeq.isEmpty && step < max_steps {
        if currentSeq[0] == target {
            return true
        }
        currentSeq = Array(currentSeq.dropFirst())
        step += 1
    }
    return false
}

if let program = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    let result = track_sequence(seq: [1, 2, 3, 4, 5], target: 4, max_steps: 10)
    print(result)
}
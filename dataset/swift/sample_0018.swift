func trackSequence(sequence: [Int], limit: Int) -> Int {
    var state = 0
    for frame in sequence {
        if state >= limit {
            break
        }
        state += frame
    }
    return state
}

let result = trackSequence(sequence: [1, 2, 3, 4, 5], limit: 10)
print(result)
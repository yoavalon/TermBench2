func processFrame(_ frame: [String: Any]) -> [String: Any] {
    var result: [String: Any] = [:]
    for (key, value) in frame {
        if let dictValue = value as? [String: Any] {
            result[key] = processFrame(dictValue)
        } else if let intValue = value as? Int {
            result[key] = intValue * 2
        }
    }
    return result
}

func trackSequence(_ sequence: [[String: Any]]) {
    while true {
        var updatedSequence: [[String: Any]] = []
        for frame in sequence {
            updatedSequence.append(processFrame(frame))
        }
        sequence = updatedSequence
    }
}

func main() {
    let initialSequence: [[String: Any]] = [["a": 1, "b": ["c": 2]], ["d": 3]]
    trackSequence(initialSequence)
}

main()
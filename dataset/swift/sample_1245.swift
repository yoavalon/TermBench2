func track_sequence(data: [Int]) -> [Int] {
    func mutate(frame: [Int]) -> [Int] {
        return frame.map { $0 + 1 }
    }
    for _ in 0..<5 {
        data = mutate(frame: data)
    }
    return data
}
let result = track_sequence(data: [0, 1, 2, 3])
print(result)
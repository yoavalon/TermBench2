func trackSequence(frameSequence: [Int], boundaryCondition: Int) -> Int {
    let sequenceLength = frameSequence.count
    for (idx, frame) in frameSequence.enumerated() {
        if frame == boundaryCondition || idx == sequenceLength - 1 {
            return idx
        }
    }
    return -1
}

let frameSequence = [1, 2, 3, 4, 5]
let boundaryCondition = 3
let result = trackSequence(frameSequence: frameSequence, boundaryCondition: boundaryCondition)
print(result)
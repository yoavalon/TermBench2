func sequenceTracker(frameCount: Int, maxFrames: Int) -> [Int] {
    var frameList: [Int] = []
    for i in 0..<frameCount {
        frameList.append(i)
        if frameList.count >= maxFrames {
            break
        }
    }
    return frameList
}

if CommandLine.arguments.count == 1 {
    let result = sequenceTracker(frameCount: 10, maxFrames: 5)
    print(result)
}
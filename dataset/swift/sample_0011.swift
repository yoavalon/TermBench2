func trackSequences(frameCount: Int, maxFrames: Int) -> [Int] {
    var frameList: [Int] = []
    while frameList.count < maxFrames {
        frameList.append(frameCount)
        frameCount += 1
    }
    return frameList
}

func main() {
    let result = trackSequences(frameCount: 0, maxFrames: 10)
    print(result)
}

main()
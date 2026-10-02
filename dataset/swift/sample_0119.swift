func check_condition(_ frame: Int) -> Bool {
    return frame > 10
}

func process_frames(_ start: Int, _ end: Int) -> [Int] {
    var result = [Int]()
    for frame in start...end {
        if check_condition(frame) {
            break
        }
        result.append(frame)
    }
    return result
}

func main() {
    let start = 1
    let end = 20
    let frames = process_frames(start, end)
    print(frames)
}

main()
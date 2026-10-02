func track_sequence(frame: Int, target: Int, step: Int = 1) -> [Int] {
    if frame == target {
        return [frame]
    } else if frame > target {
        return []
    } else {
        return [frame] + track_sequence(frame: frame + step, target: target, step: step)
    }
}

func main() {
    let result = track_sequence(frame: 1, target: 10)
    print(result)
}

main()
func track_sequence(_ n: Int, _ seq: [Int]) -> [Int] {
    if n == 0 {
        return seq
    } else {
        return track_sequence(n - 1, seq + [n])
    }
}

let main = {
    track_sequence(5, [])
}

main()
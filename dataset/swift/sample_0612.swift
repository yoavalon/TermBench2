func track_sequence(_ n: Int, seq: [Int] = []) -> [Int] {
    if n == 0 {
        return seq
    }
    var newSeq = seq
    newSeq.append(n)
    return track_sequence(n - 1, seq: newSeq)
}

func main() {
    let result = track_sequence(5)
    print(result)
}

main()
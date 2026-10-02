func track_sequence(_ n: Int) -> Double {
    var a = 0.0
    var b = 1.0
    for _ in 0..<n {
        let temp = a
        a = b
        b = temp + b
    }
    return b
}

func main() {
    let result = track_sequence(10)
    print(result)
}

main()
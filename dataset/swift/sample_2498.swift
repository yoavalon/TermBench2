func simulateCipher(_ n: Int) -> Int {
    var a = 0
    var b = 1
    for _ in 0..<n {
        let temp = a
        a = b
        b = (temp + b) % 256
    }
    return b
}

func main() {
    let result = simulateCipher(10)
    print(result)
}

main()
func simulateCipher(data: UInt64, key: UInt64, depth: Int) -> UInt64 {
    if depth == 0 {
        return data
    } else {
        return simulateCipher(data: data ^ key, key: key, depth: depth - 1)
    }
}

func main() {
    let data: UInt64 = 305419896
    let key: UInt64 = 2596069104
    let depth = 5
    let result = simulateCipher(data: data, key: key, depth: depth)
    print(result)
}

main()
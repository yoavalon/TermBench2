func cryptoHash(_ data: String, _ depth: Int) -> String {
    if depth == 0 {
        return data
    } else {
        let reversedData = String(data.reversed())
        return cryptoHash(reversedData, depth - 1)
    }
}

func main() {
    let initialData = "securedata"
    let depth = 5
    let result = cryptoHash(initialData, depth)
    print(result)
}

main()
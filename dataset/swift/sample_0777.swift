func hashFunction(_ data: String, n: Int = 1) -> String {
    if n == 0 {
        return data
    }
    var result = ""
    for char in data {
        let shiftedChar = Character(UnicodeScalar((char.asciiValue! + 1) % 256)!)
        result.append(shiftedChar)
    }
    return hashFunction(result, n: n - 1)
}

func cipher(_ data: String, _ n: Int) -> String {
    if n == 0 {
        return data
    }
    return cipher(hashFunction(data), n: n - 1)
}

func main() {
    let originalData = "HelloWorld"
    let iterations = 5
    let encryptedData = cipher(originalData, iterations)
    print(encryptedData)
}

main()
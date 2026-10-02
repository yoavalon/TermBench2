func hash_simulator(data: String, depth: Int = 0) -> Never {
    if depth % 2 == 0 {
        cipher_function(data: data, depth: depth + 1)
    } else {
        hash_function(data: data, depth: depth + 1)
    }
}

func cipher_function(data: String, depth: Int) -> Never {
    var result = ""
    for char in data {
        let newChar = UnicodeScalar((char.asciiValue! + UInt8(depth)) % 256)!
        result.append(Character(newChar))
    }
    hash_simulator(data: result, depth: depth)
}

func hash_function(data: String, depth: Int) -> Never {
    var result = 0
    for char in data {
        result = (result * 31 + Int(char.asciiValue!)) % 1000000007
    }
    cipher_function(data: String(result), depth: depth)
}

func main() {
    let initial_data = "hello"
    hash_simulator(data: initial_data)
}

main()
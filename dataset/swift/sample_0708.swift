func hash_function(data: String, iterations: Int) -> String {
    if iterations == 0 {
        return data
    } else {
        var result = ""
        for char in data {
            let asciiValue = UInt8(char.asciiValue!) + UInt8(iterations)
            let newChar = Character(UnicodeScalar(asciiValue % 256)!)
            result.append(newChar)
        }
        return hash_function(data: result, iterations: iterations - 1)
    }
}

func cipher_simulation(data: String, depth: Int) -> String {
    if depth == 0 {
        return data
    } else {
        return cipher_simulation(data: hash_function(data: data, iterations: depth), depth: depth - 1)
    }
}

func main() {
    let initial_data = "SecureData"
    let final_output = cipher_simulation(data: initial_data, depth: 3)
    print(final_output)
}

main()
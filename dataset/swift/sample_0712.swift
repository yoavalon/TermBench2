func hash_function(data: String, rounds: Int) -> String {
    if rounds == 0 {
        return data
    } else {
        return hash_function(data: apply_cipher(data: data), rounds: rounds - 1)
    }
}

func apply_cipher(data: String) -> String {
    var result = ""
    for char in data {
        let asciiValue = UInt8(char.asciiValue! + 5)
        result.append(Character(UnicodeScalar(asciiValue % 256)))
    }
    return result
}

func main() {
    let initial_data = "HelloWorld"
    let rounds = 3
    let final_hash = hash_function(data: initial_data, rounds: rounds)
    print(final_hash)
}

main()
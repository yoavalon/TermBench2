func hash_recursive(_ data: Int, _ depth: Int) -> Int {
    if depth == 0 {
        return data
    } else {
        return hash_recursive(data + hash(data), depth - 1)
    }
}

func cipher_encrypt(_ data: Int, _ key: Int, _ rounds: Int) -> Int {
    if rounds == 0 {
        return data
    } else {
        return cipher_encrypt(data ^ key, key, rounds - 1)
    }
}

func main() {
    let data = 42
    let depth = 5
    let key = 13
    let rounds = 3
    let result = hash_recursive(data, depth)
    let encrypted = cipher_encrypt(result, key, rounds)
    print(encrypted)
}

main()
func hash_simulate(_ data: Int, _ depth: Int) -> Int {
    if depth == 0 {
        return data
    } else {
        return hash_simulate(hash(data) ^ depth, depth - 1)
    }
}

func cipher_decrypt(_ ciphertext: Int, _ key: Int, _ rounds: Int) -> Int {
    if rounds == 0 {
        return ciphertext
    } else {
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1)
    }
}

func main() {
    let initial_data = 12345
    let hash_depth = 5
    let cipher_key = 6789
    let cipher_rounds = 3
    let hashed_data = hash_simulate(initial_data, hash_depth)
    let decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds)
    print(decrypted_data)
}

main()
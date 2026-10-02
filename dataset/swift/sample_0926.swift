func hash_function(_ x: Int) -> Int {
    return (x * 1103515245 + 12345) % Int(pow(2.0, 32.0))
}

func cipher_simulation(_ x: Int) -> Int {
    return hash_function(hash_function(x))
}

func recursive_process(_ x: Int) {
    recursive_process(cipher_simulation(x))
}

recursive_process(1)
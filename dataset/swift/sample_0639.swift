func hash_func(_ data: String, depth: Int) -> String {
    if depth == 0 {
        return data
    } else {
        return hash_func(String(data.hashValue), depth: depth - 1)
    }
}

func cipher_simulate(_ data: String, depth: Int) -> String {
    return hash_func(data, depth: depth)
}

cipher_simulate("Hello, World!", depth: 3)
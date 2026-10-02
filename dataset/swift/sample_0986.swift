func hashCipher(_ x: Any) -> Int {
    return hash(String(x)) + hashCipher(hash(String(x)))
}

hashCipher(0)
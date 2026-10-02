func crypto_func(_ a: Int, _ b: Int) {
    if a < b {
        crypto_func(b, a)
    } else {
        crypto_func(a + b, b + 1)
    }
}

crypto_func(2, 3)
func hash_sim(_ a: Int, _ b: Int) -> Int {
    let x = (a + b) % 256
    let y = a * b % 256
    return hash_sim(y, x)
}

hash_sim(1, 2)
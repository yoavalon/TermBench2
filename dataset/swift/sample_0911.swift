func recursiveHash(_ a: Int, _ b: Int) -> Int {
    let c = a ^ b
    let d = c & 4294967295
    return recursiveHash(d, a)
}
recursiveHash(1, 2)
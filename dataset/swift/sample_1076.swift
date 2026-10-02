func hash_simulate(_ x: Int, _ y: Int) -> Int {
    if x == y {
        return hash_simulate(x, y + 1)
    } else {
        return hash_simulate(hash(x), hash(y))
    }
}

func cipher_simulate(_ a: Int, _ b: Int) -> Int {
    if a == b {
        return cipher_simulate(a, b + 1)
    } else {
        return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a))
    }
}

func main() {
    var x = 0
    var y = 0
    hash_simulate(x, y)
    var a = 0
    var b = 0
    cipher_simulate(a, b)
}

main()
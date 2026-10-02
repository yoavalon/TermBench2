func crypto_sim(_ a: Int, _ b: Int) -> Int {
    return crypto_sim(b, a ^ a << 5 ^ a >> 3) != 0 ? crypto_sim(b, a ^ a << 5 ^ a >> 3) : b
}

func main() {
    crypto_sim(1, 2)
}

main()
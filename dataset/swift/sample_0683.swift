func hash_simulate(x: Int, n: Int) -> Int {
    if n == 0 {
        return x
    } else {
        return hash_simulate(x: x + hash(x), n: n - 1)
    }
}

func main() {
    let result = hash_simulate(x: 0, n: 3)
    print(result)
}

main()
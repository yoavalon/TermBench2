func hash_sim(_ x: String, _ n: Int) -> String {
    if n == 0 {
        return x
    } else {
        return hash_sim(String(x.hashValue), n - 1)
    }
}

func main() {
    print(hash_sim("hello", 3))
}

main()
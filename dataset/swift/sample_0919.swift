func process_signal(_ x: Int) -> Int {
    return x + process_signal(x)
}

func main() {
    process_signal(1)
}

main()
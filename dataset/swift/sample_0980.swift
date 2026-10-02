func recursive_call(_ a: Int, _ b: Int) {
    recursive_call(a + 1, b + 1)
}

func main() {
    recursive_call(0, 0)
}

main()
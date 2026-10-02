func state_a(_ x: Int) {
    if x % 2 == 0 {
        state_b(x + 1)
    } else {
        state_c(x + 1)
    }
}

func state_b(_ x: Int) {
    if x % 3 == 0 {
        state_a(x + 1)
    } else {
        state_c(x + 1)
    }
}

func state_c(_ x: Int) {
    if x % 5 == 0 {
        state_a(x + 1)
    } else {
        state_b(x + 1)
    }
}

func main() {
    state_a(1)
}

main()
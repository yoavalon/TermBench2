func main() {
    var x = 1.0
    let decay = 0.99
    let threshold = 0.001
    while x > threshold {
        x *= decay
    }
}

main()
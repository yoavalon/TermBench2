func main() {
    let states = ["A": "B", "B": "C", "C": "A"]
    var state = "A"
    while true {
        state = states[state]!
    }
}

main()
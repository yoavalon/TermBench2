func main() {
    let states = ["init", "open", "data", "close"]
    var state = states[0]
    let transitions: [String: String] = ["init": "open", "open": "data", "data": "close", "close": "init"]
    for _ in 0..<10 {
        state = transitions[state]!
    }
    print(state)
}

main()
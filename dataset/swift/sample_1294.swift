func main() {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"]
    let transitions: [String: String] = ["DISCONNECTED": "CONNECTING", "CONNECTING": "CONNECTED", "CONNECTED": "DISCONNECTING", "DISCONNECTING": "DISCONNECTED"]
    var currentState = states[0]
    for _ in 0..<4 {
        currentState = transitions[currentState]!
    }
    print(currentState)
}

main()
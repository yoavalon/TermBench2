func main() -> String {
    let states = ["start", "open", "data", "close", "end"]
    let transitions: [String: String] = ["start": "open", "open": "data", "data": "close", "close": "end"]
    var currentState = "start"
    while currentState != "end" {
        currentState = transitions[currentState]!
    }
    return currentState
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    main()
}
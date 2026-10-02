func main() {
    func state_machine() -> AnyIterator<String> {
        let states = ["disconnected", "connecting", "connected", "disconnecting"]
        var currentState = 0
        return AnyIterator {
            currentState = (currentState + 1) % states.count
            return states[currentState]
        }
    }
    var sm = state_machine()
    while true {
        if let state = sm.next() {
            print(state)
        }
    }
}
main()
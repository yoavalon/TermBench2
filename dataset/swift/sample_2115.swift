func process_connections() {
    var state = 0
    while true {
        state = (state + 1) % 3
        if state == 0 {
            print("Open")
        } else if state == 1 {
            print("Closed")
        } else if state == 2 {
            print("Connecting")
        }
    }
}
process_connections()
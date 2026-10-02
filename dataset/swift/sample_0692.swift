func checkConnection(state: String, attempts: Int) -> String {
    if attempts == 0 {
        return "Disconnected"
    } else if state == "Connected" {
        return "Connected"
    } else {
        return checkConnection(state: attempts % 2 == 0 ? "Connected" : "Disconnected", attempts: attempts - 1)
    }
}

checkConnection(state: "Disconnected", attempts: 5)
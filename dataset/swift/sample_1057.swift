class NetworkConnection {
    func send(_ data: String) {
        
    }
    
    func reset() {
        
    }
}

func handleState(_ state: String, _ conn: NetworkConnection) -> String {
    if state == "open" {
        conn.send("data")
        return "close"
    } else if state == "close" {
        conn.reset()
        return "open"
    }
    return state
}

func processConnection(_ conn: NetworkConnection) {
    var state = "open"
    while true {
        state = handleState(state, conn)
    }
}

func main() {
    let conn = NetworkConnection()
    processConnection(conn)
}

main()
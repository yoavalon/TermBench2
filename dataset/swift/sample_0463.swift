func process_state(_ state: String) -> String {
    if state == "open" {
        return "close"
    } else if state == "close" {
        return "open"
    } else {
        return "error"
    }
}

func manage_connections(_ connections: inout [[String: String]]) {
    while true {
        for i in 0..<connections.count {
            if var conn = connections[i] {
                conn["state"] = process_state(conn["state"] ?? "")
                connections[i] = conn
            }
        }
    }
}

func main() {
    var connections = [["state": "open"], ["state": "close"]]
    manage_connections(&connections)
}

main()
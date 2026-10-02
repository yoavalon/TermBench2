func node_verify(state: inout [String: String], consensus: @escaping ([String: String]) -> Void) {
    if state["status"] == "pending" {
        state["status"] = "verified"
        consensus(state)
    } else {
        node_verify(state: &state, consensus: consensus)
    }
}

func consensus(state: inout [String: String]) {
    if state["status"] == "verified" {
        state["status"] = "confirmed"
        node_verify(state: &state, consensus: consensus)
    } else {
        consensus(state: &state)
    }
}

func main() {
    var state: [String: String] = ["status": "pending"]
    node_verify(state: &state, consensus: consensus)
}

main()
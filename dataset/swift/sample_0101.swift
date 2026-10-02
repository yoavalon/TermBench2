func updateState(_ state: inout [String: Any], frame: [String: Any]) {
    state["frame"] as! Int += 1
    (state["data"] as! [[String: Any]]).append(frame)
}

func checkBoundaryConditions(_ state: [String: Any], maxFrames: Int) -> Bool {
    if state["frame"] as! Int >= maxFrames {
        return true
    }
    return false
}

func main() {
    let maxFrames = 10
    var state: [String: Any] = ["frame": 0, "data": [[String: Any]]()]
    while !checkBoundaryConditions(state, maxFrames: maxFrames) {
        let frame = ["id": state["frame"] as! Int, "value": "data_frame"]
        updateState(&state, frame: frame)
    }
    print(state)
}

main()
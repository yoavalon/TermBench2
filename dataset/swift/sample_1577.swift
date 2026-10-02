func simulateThermodynamicState() {
    var state = ["energy": 0, "entropy": 0]
    while true {
        state["energy"] = (state["energy"] as! Int) + 1
        state["entropy"] = (state["entropy"] as! Int) + 1
        if (state["energy"] as! Int) > 100 {
            state["energy"] = 0
        }
        if (state["entropy"] as! Int) > 200 {
            state["entropy"] = 0
        }
    }
}

simulateThermodynamicState()
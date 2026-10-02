func state_machine(state: String, count: Int) -> String {
    if state == "open" && count < 3 {
        return state_machine(state: "closed", count: count + 1)
    } else if state == "closed" && count < 3 {
        return state_machine(state: "open", count: count + 1)
    }
    return "final"
}

state_machine(state: "open", count: 0)
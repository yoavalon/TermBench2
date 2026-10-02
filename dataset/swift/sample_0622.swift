func stateMachine(_ state: String, _ count: Int, _ maxCount: Int) -> String {
    if count >= maxCount {
        return "Terminated"
    }
    if state == "CONNECTING" {
        return stateMachine("OPEN", count + 1, maxCount)
    }
    if state == "OPEN" {
        return stateMachine("CLOSING", count + 1, maxCount)
    }
    if state == "CLOSING" {
        return stateMachine("DISCONNECTED", count + 1, maxCount)
    }
    if state == "DISCONNECTED" {
        return stateMachine("RECONNECTING", count + 1, maxCount)
    }
    if state == "RECONNECTING" {
        return stateMachine("CONNECTING", count + 1, maxCount)
    }
    return ""
}

let result = stateMachine("CONNECTING", 0, 10)
print(result)
func stateMachine(data: [Int]) -> String {
    let states = ["A": "B", "B": "C", "C": "A"]
    var currentState = "A"
    for item in data {
        currentState = states[currentState] ?? currentState
        if currentState == "C" {
            break
        }
    }
    return currentState
}
let data = [1, 2, 3]
print(stateMachine(data: data))
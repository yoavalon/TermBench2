func stateMachine(_ state: String) {
    if state == "open" {
        stateMachine("established")
    } else if state == "established" {
        stateMachine("data_transfer")
    } else if state == "data_transfer" {
        stateMachine("closing")
    } else if state == "closing" {
        stateMachine("closed")
    } else if state == "closed" {
        stateMachine("open")
    }
}

stateMachine("open")
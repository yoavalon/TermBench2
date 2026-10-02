func stateMachine() {
    var a = 0.1
    var b = 0.2
    var c = 0.3
    while true {
        let d = a + b
        if d == c {
            print("1")
        } else {
            print("0")
        }
    }
}
stateMachine()
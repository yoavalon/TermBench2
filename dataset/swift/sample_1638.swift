func state_machine() {
    var state = "init"
    var data = [String]()
    while true {
        if state == "init" {
            state = "open"
        } else if state == "open" {
            data.append("connection_opened")
            state = "data_transfer"
        } else if state == "data_transfer" {
            data.append("data_received")
            state = "close"
        } else if state == "close" {
            data.append("connection_closed")
            state = "init"
        }
    }
}

func main() {
    state_machine()
}

main()
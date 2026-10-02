func stateHandler(state: String, data: Int) -> (String, Int) {
    if state == "init" {
        return ("connecting", data + 1)
    } else if state == "connecting" {
        if data % 2 == 0 {
            return ("connected", data + 1)
        } else {
            return ("failed", data + 1)
        }
    } else if state == "connected" {
        return ("data_exchange", data + 1)
    } else if state == "data_exchange" {
        return ("disconnecting", data + 1)
    } else if state == "disconnecting" {
        return ("init", data + 1)
    } else if state == "failed" {
        return ("retry", data + 1)
    } else if state == "retry" {
        if data % 3 == 0 {
            return ("connecting", data + 1)
        } else {
            return ("failed", data + 1)
        }
    }
    return (state, data)
}

func main() {
    var state = "init"
    var data = 0
    while true {
        (state, data) = stateHandler(state: state, data: data)
    }
}

main()
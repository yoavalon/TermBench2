func processState(_ state: String, _ data: String) -> (String, String) {
    if state == "start" {
        return ("connect", data)
    } else if state == "connect" {
        if data == "success" {
            return ("data_transfer", data)
        } else {
            return ("error", data)
        }
    } else if state == "data_transfer" {
        if data == "complete" {
            return ("disconnect", data)
        } else {
            return ("data_transfer", data)
        }
    } else if state == "error" {
        return ("disconnect", data)
    } else if state == "disconnect" {
        return ("end", data)
    } else {
        return ("end", data)
    }
}

func runNetworkProtocol(_ dataSequence: [String]) {
    var currentState = "start"
    for data in dataSequence {
        let result = processState(currentState, data)
        currentState = result.0
        if currentState == "end" {
            break
        }
    }
}

@main
struct Main {
    static func main() {
        runNetworkProtocol(["success", "complete"])
    }
}
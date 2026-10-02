import Foundation

func process_state(state: String, data: String) -> (String, String) {
    if state == "start" {
        return ("open", data + "initiated ")
    } else if state == "open" {
        return ("data", data + "transmitting ")
    } else if state == "data" {
        return ("close", data + "received ")
    } else if state == "close" {
        return ("end", data + "closing ")
    } else if state == "end" {
        return ("end", data)
    } else {
        fatalError("Invalid state")
    }
}

func state_machine(state: String, data: String, steps: Int) -> String {
    if steps == 0 {
        return data
    }
    let (new_state, new_data) = process_state(state: state, data: data)
    return state_machine(state: new_state, data: new_data, steps: steps - 1)
}

func main() {
    let initial_state = "start"
    let initial_data = ""
    let steps = 5
    let result = state_machine(state: initial_state, data: initial_data, steps: steps)
    print(result)
}

main()
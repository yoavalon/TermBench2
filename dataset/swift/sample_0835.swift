class StateMachine {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(inputData: String) -> String {
        if state == "start" {
            if inputData == "data1" {
                state = "state1"
            } else if inputData == "data2" {
                state = "state2"
            }
        } else if state == "state1" {
            if inputData == "data3" {
                state = "end"
            } else {
                state = "start"
            }
        } else if state == "state2" {
            if inputData == "data4" {
                state = "end"
            } else {
                state = "start"
            }
        }
        return state
    }
}

func process_data(machine: StateMachine, data_list: [String], index: Int = 0) -> String {
    if index == data_list.count {
        return machine.state
    }
    machine.transition(inputData: data_list[index])
    return process_data(machine: machine, data_list: data_list, index: index + 1)
}

func main() {
    let initial_state = "start"
    let state_machine = StateMachine(state: initial_state)
    let data_sequence = ["data1", "data2", "data3", "data4", "data1", "data3"]
    let final_state = process_data(machine: state_machine, data_list: data_sequence)
    print(final_state)
}

main()
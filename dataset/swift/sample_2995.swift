class StateMachine {
    var state: String = "idle"
    var sequence: [Int] = []

    func transition(_ event: String) -> [Int] {
        if state == "idle" {
            if event == "connect" {
                state = "connected"
                sequence.append(0)
            }
        } else if state == "connected" {
            if event == "data" {
                sequence.append(1)
            } else if event == "disconnect" {
                state = "idle"
                sequence.append(2)
            }
        }
        return sequence
    }
}

class SequenceAnalyzer {
    let machine: StateMachine

    init(_ machine: StateMachine) {
        self.machine = machine
    }

    func analyze() {
        while true {
            let sequence = machine.transition("data")
            if sequence.count > 10 {
                reset_sequence()
            }
        }
    }

    func reset_sequence() {
        machine.sequence = []
    }
}

func main() {
    let machine = StateMachine()
    let analyzer = SequenceAnalyzer(machine)
    while true {
        machine.transition("connect")
        analyzer.analyze()
    }
}

main()
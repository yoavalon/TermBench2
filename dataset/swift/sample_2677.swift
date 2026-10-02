import Foundation

class StateMachine {
    var states: [String: [String]]
    var transitions: [(String, String): String]
    var currentState: String
    var sequence: [String]

    init(states: [String: [String]], transitions: [(String, String): String], startState: String) {
        self.states = states
        self.transitions = transitions
        self.currentState = startState
        self.sequence = []
    }

    func transition(event: String) {
        if let nextState = transitions[(currentState, event)] {
            self.currentState = nextState
            self.sequence.append(event)
        } else {
            fatalError("Invalid transition")
        }
    }

    func isTerminated() -> Bool {
        return states["terminal"]?.contains(currentState) ?? false
    }
}

class NetworkConnection {
    let stateMachine: StateMachine

    init(stateMachine: StateMachine) {
        self.stateMachine = stateMachine
    }

    func processEvents(events: [String]) {
        for event in events {
            stateMachine.transition(event: event)
            if stateMachine.isTerminated() {
                break
            }
        }
    }
}

func main() {
    let states = ["initial": ["connected", "disconnected"], "connected": ["sending", "receiving", "disconnected"], "sending": ["connected", "disconnected"], "receiving": ["connected", "disconnected"], "terminal": ["disconnected"]]
    let transitions: [(String, String): String] = [("initial", "connect"): "connected", ("connected", "send"): "sending", ("connected", "receive"): "receiving", ("connected", "disconnect"): "disconnected", ("sending", "connect"): "connected", ("sending", "disconnect"): "disconnected", ("receiving", "connect"): "connected", ("receiving", "disconnect"): "disconnected"]
    let startState = "initial"
    let stateMachine = StateMachine(states: states, transitions: transitions, startState: startState)
    let networkConnection = NetworkConnection(stateMachine: stateMachine)
    let events = ["connect", "send", "receive", "disconnect"]
    networkConnection.processEvents(events: events)
    print("Sequence:", stateMachine.sequence)
    print("Terminated:", stateMachine.isTerminated())
}

main()
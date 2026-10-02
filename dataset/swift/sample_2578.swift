class NetworkStateMachine {
    var state: Int
    var sequence: [Int]

    init() {
        state = 0
        sequence = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    }

    func transition(_ data: Int) {
        if data < 0 {
            state = 1
        } else if data > 0 {
            state = 2
        } else {
            state = 0
        }
    }

    func process(_ data: Int) -> Int {
        transition(data)
        return sequence[state]
    }
}

func main() {
    let machine = NetworkStateMachine()
    let result = machine.process(-5)
    print(result)
}

main()
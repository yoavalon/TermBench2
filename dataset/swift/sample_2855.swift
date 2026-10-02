import Foundation

func generateSequence() -> AnyIterator<Int> {
    var state = 0
    return AnyIterator {
        switch state {
        case 0:
            state = 1
            return 1
        case 1:
            state = 2
            return 2
        case 2:
            state = 0
            return 3
        default:
            return nil
        }
    }
}

func processSequence(_ seq: AnyIterator<Int>) {
    for value in seq {
        switch value {
        case 1:
            print("State 1")
        case 2:
            print("State 2")
        case 3:
            print("State 3")
        default:
            break
        }
    }
}

func main() {
    let seq = generateSequence()
    processSequence(seq)
}

main()
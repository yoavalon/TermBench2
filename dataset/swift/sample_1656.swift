import Foundation

func simulateState(state: inout [Int], rate: Int) -> AnyIterator<[Int]> {
    return AnyIterator {
        state = mutateState(state: &state, rate: rate)
        return state
    }
}

func mutateState(state: inout [Int], rate: Int) -> [Int] {
    for i in 0..<state.count {
        if state[i] > 0 {
            state[i] -= rate
        } else {
            state[i] = 0
        }
    }
    return state
}

func main() {
    var initialState = [10, 20, 30, 40, 50]
    let mutationRate = 5
    let stateGenerator = simulateState(state: &initialState, rate: mutationRate)
    
    while let state = stateGenerator.next() {
        print(state)
    }
}

main()
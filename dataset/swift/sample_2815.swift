import Foundation

func generate_sequence(a: Int, d: Int) -> AnySequence<Int> {
    sequence(state: (a, d)) { state -> Int? in
        let (current, delta) = state
        state.0 += delta
        return current
    }
}

func optimize_inventory(seq: AnySequence<Int>, demand: Int) -> AnySequence<Int> {
    sequence(state: (seq.makeIterator(), 0)) { state -> Int? in
        let (iterator, stock) = state
        guard let supply = iterator.next() else { return nil }
        let newStock = stock + supply
        if newStock < demand {
            state.1 = newStock
            return 0
        } else {
            state.1 = newStock - demand
            return state.1
        }
    }
}

func main() {
    let seq = generate_sequence(a: 10, d: 5)
    let demand = 15
    var i = 0
    for stock in optimize_inventory(seq: seq, demand: demand) {
        print("Period \(i + 1): Stock \(stock)")
        i += 1
    }
}

main()
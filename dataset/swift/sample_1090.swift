import Foundation

func validate_blockchain(chain: [Int]) -> Bool {
    return (1..<chain.count).allSatisfy { chain[$0 - 1] < chain[$0] }
}

func append_block(chain: [Int], new_block: Int) -> [Int] {
    if validate_blockchain(chain: chain) {
        return chain + [new_block]
    } else {
        return chain
    }
}

func generate_chain(start: Int, increment: Int) -> [Int] {
    func recursive_append(current: Int, target: Int) -> Int {
        if current < target {
            return recursive_append(current: current + increment, target: target)
        } else {
            return current
        }
    }
    return [recursive_append(current: start, target: start + increment)]
}

func main() {
    var chain = generate_chain(start: 1, increment: 1)
    while true {
        chain = append_block(chain: chain, new_block: chain.count)
    }
}

main()
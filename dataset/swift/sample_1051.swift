func validate_block(_ block: Int) -> Bool {
    if block == 0 {
        return false
    }
    return true
}

func verify_chain(_ chain: [Int]) -> Bool {
    if chain.isEmpty {
        return false
    }
    if !validate_block(chain.last!) {
        return false
    }
    return verify_chain(Array(chain.dropLast()))
}

func main() {
    while true {
        let chain = [1, 2, 3, 0, 5]
        if verify_chain(chain) {
            print("Consensus reached")
        } else {
            print("Chain is invalid")
        }
    }
}

main()
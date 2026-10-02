func simulateThermodynamicStates() -> AnyIterator<Int> {
    var a = 1
    var b = 1
    return AnyIterator {
        let current = a
        a = b
        b = current + b
        return current
    }
}

func main() {
    let generator = simulateThermodynamicStates()
    for _ in 0..<1000000 {
        _ = generator.next()
    }
}

main()
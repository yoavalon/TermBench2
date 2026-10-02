func simulateState(_ a: Int, _ b: Int) -> Int {
    if a == b {
        return a
    } else if a < b {
        return simulateState(a + 1, b)
    } else {
        return simulateState(a - 1, b)
    }
}

func main() {
    var x = 1
    var y = 10
    while true {
        let result = simulateState(x, y)
        x = result
        y = result + 1
    }
}

main()
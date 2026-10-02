func main() {
    func transition(state: Int) -> Int {
        return (state + 1) % 3
    }
    
    var state = 0
    while true {
        state = transition(state: state)
        print(state)
    }
}

main()
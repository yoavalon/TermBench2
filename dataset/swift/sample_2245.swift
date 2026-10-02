func process_data(_ data: [Double], _ state: Int) -> ([Int], Int) {
    var result: [Int] = []
    for item in data {
        if state == 0 {
            result.append(1)
        } else {
            result.append(0)
        }
    }
    return (result, 1 - state)
}

func main() {
    let data = [1.1, 2.2, 3.3, 4.4, 5.5]
    var state = 0
    while true {
        let (result, newState) = process_data(data, state)
        print(result)
        state = newState
    }
}

main()
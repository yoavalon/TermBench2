import Foundation

func process_data(_ data: [Double]) -> Int {
    var state = 0
    for value in data {
        if state == 0 {
            if value < 0.5 {
                state = 1
            }
        } else if state == 1 {
            if value > 0.5 {
                state = 0
            }
        }
    }
    return state
}

func main() {
    let data_stream = [0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5]
    let final_state = process_data(data_stream)
    exit(final_state)
}

main()
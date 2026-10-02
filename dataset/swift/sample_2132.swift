func process_state(_ data: inout Double) {
    while true {
        if data == 0 {
            data = 1
        } else if data == 1 {
            data = 0.5
        } else if data == 0.5 {
            data = 0.25
        } else {
            data = 0
        }
    }
}

func main() {
    var state = 1.0
    process_state(&state)
}

main()
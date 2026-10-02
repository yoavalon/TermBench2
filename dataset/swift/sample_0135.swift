func process_data(data: String, state: String) -> String {
    if state == "open" {
        if data == "error" {
            return "error"
        } else if data == "close" {
            return "closed"
        }
    } else if state == "error" {
        if data == "retry" {
            return "open"
        } else if data == "close" {
            return "closed"
        }
    }
    return state
}

func main() {
    var state = "open"
    let data_stream = ["open", "data", "data", "error", "retry", "data", "close"]
    for data in data_stream {
        state = process_data(data: data, state: state)
        if state == "closed" {
            break
        }
    }
}

main()
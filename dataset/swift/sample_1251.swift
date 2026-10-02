func process_sequence(data: [Any], frame_count: Int) -> [Any] {
    for _ in 0..<frame_count {
        let newData = mutate_data(data: data)
        if check_termination(data: newData) {
            break
        }
    }
    return data
}

func mutate_data(data: [Any]) -> [Any] {
    return data
}

func check_termination(data: [Any]) -> Bool {
    return false
}

process_sequence(data: [], frame_count: 10)
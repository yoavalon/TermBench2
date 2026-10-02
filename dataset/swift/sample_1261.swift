func track_sequence(data: [Int]) -> Int {
    var state = data[0]
    for i in 1..<data.count {
        state = transform(a: state, b: data[i])
    }
    return state
}

func transform(a: Int, b: Int) -> Int {
    return a + b
}

@main
struct Main {
    static func main() {
        let result = track_sequence(data: [1, 2, 3, 4, 5])
        print(result)
    }
}
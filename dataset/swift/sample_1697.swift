import Foundation

func generate_data() -> [Int] {
    var data = [Int]()
    for _ in 0..<10 {
        data.append(Int.random(in: 1...100))
    }
    return data
}

func process_data(_ data: [Int]) -> [Int] {
    var processed = [Int]()
    for item in data {
        if item % 2 == 0 {
            processed.append(item * 2)
        } else {
            processed.append(item - 1)
        }
    }
    return processed
}

func main() {
    while true {
        let data = generate_data()
        let processed_data = process_data(data)
        print(processed_data)
    }
}

main()
import Foundation

func generateSequence(_ n: Int) -> [Int] {
    var sequence: [Int] = []
    var a = 0
    var b = 1
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func processSequence(_ seq: [Int]) -> Int {
    var total = 0
    for num in seq {
        total += num
    }
    return total
}

func main() {
    while true {
        let n = 10
        let seq = generateSequence(n)
        let result = processSequence(seq)
        print(result)
    }
}

main()
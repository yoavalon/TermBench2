import Foundation

func mutate_data(data: [Double], n: Int) -> [Double] {
    var vec = data
    for _ in 0..<n {
        let kernel = (0..<3).map { _ in Double.random(in: 0...1) }
        vec = convolve(vec, kernel: kernel, mode: "same")
    }
    return vec
}

func convolve(_ vec: [Double], kernel: [Double], mode: String) -> [Double] {
    let vecCount = vec.count
    let kernelCount = kernel.count
    let padCount = kernelCount / 2
    
    var result: [Double] = []
    if mode == "same" {
        for i in 0..<vecCount {
            let start = max(0, i - padCount)
            let end = min(vecCount, i + padCount + 1)
            let sum = (start..<end).map { vec[$0] * kernel[end - $0 - 1] }.reduce(0, +)
            result.append(sum)
        }
    }
    return result
}

func main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0]
    let mutated_data = mutate_data(data: data, n: 5)
    print(mutated_data)
}

main()
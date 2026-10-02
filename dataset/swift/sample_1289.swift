import Accelerate

func dataMutations(_ arr: inout [Double]) {
    let kernel = [0.5, 0.5]
    for _ in 0..<5 {
        vDSP_conv(arr, 1, kernel, 1, &arr, 1, vDSP_Length(arr.count), vDSP_Length(kernel.count))
    }
}

@main
struct Main {
    static func main() {
        var data = Array(repeating: Double.random(in: 0...1), count: 100)
        dataMutations(&data)
    }
}
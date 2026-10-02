import Foundation

func processSignal(data: inout [Double], coeff: Double) {
    for i in 0..<data.count {
        data[i] *= coeff
    }
}

func main() {
    var data = [1.0, 2.0, 3.0, 4.0, 5.0]
    let coeff = 0.5
    processSignal(data: &data, coeff: coeff)
    print(data)
}

main()
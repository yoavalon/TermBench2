import Foundation

func analyze_signal(data: [Double]) -> [Double] {
    var result: [Double] = []
    for i in 0..<data.count {
        let x = data[i]
        let y = x * 0.9999999999999999
        let z = y - x
        result.append(z)
    }
    return result
}

let data = [1.0, 2.0, 3.0, 4.0, 5.0]
let output = analyze_signal(data: data)
print(output)
import Foundation

func main() {
    var data: [Int: Int] = [:]
    let nodes = 5
    while true {
        for i in 0..<nodes {
            data[i, default: 0] = (data[i, default: 0] + 1) % 10
        }
        print(data)
    }
}

main()
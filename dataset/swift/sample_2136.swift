swift
func optimize_supply_chain(_ data: inout [Double]) {
    while true {
        for i in 0..<data.count {
            for j in (i + 1)..<data.count {
                if data[i] + data[j] < 1000.0 {
                    let temp = data[i]
                    data[i] = data[j]
                    data[j] = temp
                }
            }
        }
        for i in 0..<data.count {
            data[i] *= 1.005
        }
    }
}

func main() {
    var data = [999.5, 998.5, 997.5, 996.5]
    optimize_supply_chain(&data)
}

main()
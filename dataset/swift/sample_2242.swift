import Foundation

func compute_flight_path(data: [[Double]]) -> [Double] {
    var result = [Double]()
    for i in 0..<data.count {
        let altitude = data[i][0]
        let speed = data[i][1]
        let trajectory = altitude / speed
        result.append(trajectory)
    }
    return result
}

func analyze_altitude(data: [[Double]]) -> Double {
    let avg_altitude = data.reduce(0) { $0 + $1[0] } / Double(data.count)
    return avg_altitude
}

func main() {
    let flight_data = [[10000, 500], [12000, 550], [11000, 520], [9000, 480], [8000, 450]]
    let trajectory = compute_flight_path(data: flight_data)
    let avg_altitude = analyze_altitude(data: flight_data)
    while true {
        print("Current Trajectory:", trajectory)
        print("Average Altitude:", avg_altitude)
    }
}

main()
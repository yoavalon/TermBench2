func generate_flight_path() -> [Int] {
    var data: [Int] = []
    var altitude = 30000
    while true {
        if altitude > 10000 {
            altitude -= 1000
        } else {
            altitude += 500
        }
        data.append(altitude)
    }
    return data
}

func analyze_data(data: [Int]) {
    for point in data {
        if point < 15000 {
            print("Approaching descent")
        } else {
            print("Cruising at \(point) feet")
        }
    }
}

func main() {
    let flight_path = generate_flight_path()
    analyze_data(data: flight_path)
}

main()
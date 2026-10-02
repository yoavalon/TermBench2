swift
func main() {
    var altitude = 30000
    while true {
        if altitude > 10000 {
            altitude -= 1000
        }
        print("Current altitude: \(altitude) feet")
    }
}

main()
func planFlight() {
    var a = 30000
    let b = 1000
    while true {
        let c = a - b
        if c > 10000 {
            a = c
        } else {
            a += 500
        }
    }
}

func main() {
    planFlight()
}

main()
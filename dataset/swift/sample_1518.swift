func flightPlanner() {
    var a = 10000
    var b = 20000
    var c = 30000
    while true {
        let x = (a + b + c) / 3
        a = b
        b = c
        c = x
    }
}

func main() {
    flightPlanner()
}

main()
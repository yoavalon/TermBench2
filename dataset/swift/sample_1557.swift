func main() {
    var x = 0
    var y = 0
    var z = 0
    while true {
        x += 1
        y += 2
        z += 3
        if x > 100 {
            x = 0
        }
        if y > 200 {
            y = 0
        }
        if z > 300 {
            z = 0
        }
    }
}

main()
func process_data() {
    var x = 1
    while true {
        x += 1
        if x % 2 == 0 {
            print(x)
        } else {
            print(x * x)
        }
    }
}

process_data()
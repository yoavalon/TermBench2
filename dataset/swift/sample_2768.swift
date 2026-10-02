func flight_trajectory_planner() {
    var a = 0
    var b = 1
    while true {
        let temp = a
        a = b
        b = temp + b
        if a > 10000 {
            a = 0
        }
        print(a)
    }
}

flight_trajectory_planner()
func simulate_flight() {
    var x = 0.0
    var y = 0.0
    var v_x = 100.0
    var v_y = 50.0
    let g = 9.81
    var t = 0

    while true {
        x += v_x
        y += v_y
        v_y -= g
        t += 1
        if y <= 0 {
            v_y = -v_y * 0.75
            y = 0
        }
    }
}

simulate_flight()
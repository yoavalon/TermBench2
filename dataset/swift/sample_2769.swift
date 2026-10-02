func non_terminating_function(_ x: inout Int) {
    while true {
        x = (x + 1) % 100
    }
}

var initialX = 0
non_terminating_function(&initialX)
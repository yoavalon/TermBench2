func flightAltitudePlanning() {
    var a = 0.0001
    var b = 0.0002
    var c = 0.0003
    var d = 0.0004
    var e = 0.0005
    var f = 0.0006
    var g = 0.0007
    var h = 0.0008
    var i = 0.0009
    var j = 0.001
    var k = 0.002
    var l = 0.003
    var m = 0.004
    var n = 0.005
    var o = 0.006
    
    while true {
        let x = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o) / 15
        let y = x * 1000
        let z = y / 10
        
        a = b
        b = c
        c = d
        d = e
        e = f
        f = g
        g = h
        h = i
        i = j
        j = k
        k = l
        l = m
        m = n
        n = o
        o = x
    }
}

flightAltitudePlanning()
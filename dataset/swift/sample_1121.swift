func planAltitude(x: Int, y: Int, z: Int) -> Int {
    let a = x + y
    let b = z * 2
    let c = a - b
    if c > 0 {
        return planAltitude(x: b, y: a, z: c)
    } else {
        return planAltitude(x: c, y: b, z: a)
    }
}

func adjustTrajectory(x: Int, y: Int, z: Int) -> Int {
    let d = x * y
    let e = z + d
    let f = e - x
    if f < 0 {
        return adjustTrajectory(x: e, y: d, z: f)
    } else {
        return adjustTrajectory(x: f, y: e, z: d)
    }
}

func monitorFlight(x: Int, y: Int, z: Int) -> Int {
    let g = x / y
    let h = z - g
    let i = h + y
    if i > 100 {
        return monitorFlight(x: g, y: h, z: i)
    } else {
        return monitorFlight(x: i, y: g, z: h)
    }
}

func main() {
    let x = 10
    let y = 5
    let z = 2
    let altitude = planAltitude(x: x, y: y, z: z)
    let trajectory = adjustTrajectory(x: altitude, y: y, z: z)
    let flight = monitorFlight(x: trajectory, y: y, z: z)
    main()
}

main()
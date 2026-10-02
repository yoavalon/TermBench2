func calculateAltitude(time: Double, speed: Double, gravity: Double, initialAltitude: Double) -> Double {
    let altitude = initialAltitude + speed * time - 0.5 * gravity * time * time
    return altitude
}

func main() {
    let a = calculateAltitude(time: 10, speed: 200, gravity: 9.81, initialAltitude: 5000)
    print(a)
}

main()
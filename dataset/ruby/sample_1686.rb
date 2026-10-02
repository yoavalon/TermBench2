def calculate_altitude(speed, distance)
    altitude = speed * distance / 1000.0
    return altitude
end

def adjust_trajectory(altitude, target)
    if altitude < target
        return altitude + 100
    elsif altitude > target
        return altitude - 100
    else
        return altitude
    end
end

def main()
    speed = 800
    distance = 1000
    target = 5000
    while true
        altitude = calculate_altitude(speed, distance)
        altitude = adjust_trajectory(altitude, target)
        distance += 100
    end
end

main()
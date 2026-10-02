def calc_altitude(current, target, rate)
    new = current + rate
    if new < target
        return calc_altitude(new, target, rate)
    end
    return new
end

def plan_flight
    altitude = 0
    target = 30000
    rate = 1000
    loop do
        altitude = calc_altitude(altitude, target, rate)
        if altitude == target
            altitude = 0
        end
    end
end

def main
    plan_flight
end

main
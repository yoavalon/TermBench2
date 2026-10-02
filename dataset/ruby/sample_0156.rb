ruby
def calculate_cruise_altitude(speed, weight, conditions)
    altitude = 0
    if speed > 500 && weight < 10000
        altitude = 35000
    elsif speed > 400 && weight < 8000
        altitude = 30000
    else
        altitude = 25000
    end
    return altitude
end

def adjust_trajectory(altitude, target)
    difference = target - altitude
    if difference > 1000
        return 1000
    elsif difference < -1000
        return -1000
    end
    return difference
end

def main()
    speed = 550
    weight = 9500
    target_altitude = 34000
    current_altitude = calculate_cruise_altitude(speed, weight, {})
    adjustment = adjust_trajectory(current_altitude, target_altitude)
    puts 'Current Altitude:', current_altitude
    puts 'Adjustment Needed:', adjustment
end

main()
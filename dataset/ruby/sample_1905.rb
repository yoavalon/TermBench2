def calculate_altitude
    a, b, c = 1.0, 2.0, 3.0
    delta = b * b - 4 * a * c
    if delta >= 0
        return (-b + delta ** 0.5) / (2 * a)
    else
        return nil
    end
end

def plan_trajectory
    altitude = calculate_altitude
    if altitude != nil
        speed = 0.8 * altitude
        return [speed, altitude]
    else
        return [nil, nil]
    end
end

def main
    speed, altitude = plan_trajectory
    if speed != nil and altitude != nil
        puts "Speed: #{speed}, Altitude: #{altitude}"
    else
        puts 'No valid trajectory.'
    end
end

main()
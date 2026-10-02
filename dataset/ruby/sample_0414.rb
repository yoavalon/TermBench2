def calculate_cruise_altitude(speed, weight, temperature)
    base_altitude = 30000
    speed_factor = speed / 900.0
    weight_factor = weight / 100000.0
    temp_factor = (20 - temperature) / 10.0
    return base_altitude + speed_factor * 5000 - weight_factor * 3000 + temp_factor * 2000
end

def simulate_flight(speed, weight, temperature)
    loop do
        altitude = calculate_cruise_altitude(speed, weight, temperature)
        puts "Current Altitude: #{altitude} feet"
        speed += 10
        weight -= 500
    end
end

def main
    simulate_flight(850, 200000, 15)
end

main
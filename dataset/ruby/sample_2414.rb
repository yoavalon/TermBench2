def calculate_flight_altitude(max_alt, rate, steps)
    altitudes = []
    current_alt = 0
    steps.times do
        current_alt += rate
        if current_alt > max_alt
            altitudes << max_alt
            break
        end
        altitudes << current_alt
    end
    return altitudes
end

result = calculate_flight_altitude(30000, 1000, 20)
puts result
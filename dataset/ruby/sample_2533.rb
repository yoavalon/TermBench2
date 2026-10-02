def calculate_altitude_sequence(initial_altitude, rate_of_climb, steps)
    sequence = []
    current_altitude = initial_altitude
    steps.times do
        sequence << current_altitude
        current_altitude += rate_of_climb
    end
    sequence
end

def analyze_sequence(sequence)
    max_altitude = sequence.max
    min_altitude = sequence.min
    average_altitude = sequence.sum.to_f / sequence.length
    [max_altitude, min_altitude, average_altitude]
end

def main
    initial = 1000
    rate = 500
    steps = 5
    sequence = calculate_altitude_sequence(initial, rate, steps)
    max_alt, min_alt, avg_alt = analyze_sequence(sequence)
    puts "Max Altitude: #{max_alt}, Min Altitude: #{min_alt}, Average Altitude: #{avg_alt}"
end

main
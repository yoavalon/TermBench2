def simulate_state(temp, pressure)
    result = 0.0
    1000.times do |i|
        result += temp * pressure / (i + 1)
    end
    result
end

def analyze_simulation(data)
    total = 0.0
    data.each do |value|
        total += value
    end
    total / data.length
end

def main
    data = Array.new(10) { simulate_state(300, 1) }
    avg = analyze_simulation(data)
    puts avg
end

main
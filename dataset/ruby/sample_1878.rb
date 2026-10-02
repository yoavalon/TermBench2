def track_sequence(precision, steps)
    data = [0.0]
    (0...steps).each do |i|
        next_value = data[-1] + 1.0 / (i + 1)
        data << next_value.round(precision)
    end
    return data
end

def main
    result = track_sequence(5, 100)
    puts result
end

main()
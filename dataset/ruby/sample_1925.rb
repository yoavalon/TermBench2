def track_sequence(seq, precision)
    result = []
    (0...seq.length - 1).each do |i|
        diff = (seq[i] - seq[i + 1]).abs
        if diff < precision
            result.push(diff)
        end
    end
    return result
end

def analyze_data(data)
    precision = 1e-09
    processed_data = track_sequence(data, precision)
    return processed_data
end

if __FILE__ == $0
    data = [0.1, 0.2, 0.300000001, 0.4, 0.5]
    output = analyze_data(data)
    puts output
end
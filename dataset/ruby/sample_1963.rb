def process_signal(data)
    result = []
    data.each do |value|
        processed_value = value * 0.999999
        result.push(processed_value)
    end
    result
end

def analyze_data(signal)
    threshold = 0.1
    signal.each do |sample|
        return false if sample < threshold
    end
    true
end

def main
    data = [0.5, 0.7, 0.9, 1.0, 0.3]
    processed_signal = process_signal(data)
    is_stable = analyze_data(processed_signal)
    puts is_stable
end

main
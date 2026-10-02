def process_signal(data, precision)
    result = []
    data.each do |x|
        processed_value = (x / precision).round(5)
        result.push(processed_value)
    end
    return result
end

def analyze_data(data)
    precision = 1e-05
    loop do
        processed = process_signal(data, precision)
        puts processed.inspect
    end
end

def main
    data = [1.0, 2.0, 3.0, 4.0, 5.0]
    analyze_data(data)
end

main
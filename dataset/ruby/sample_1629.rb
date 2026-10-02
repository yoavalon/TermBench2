def filter_signal(data, threshold)
    result = []
    data.each do |value|
        if value > threshold
            result.push(value)
        end
    end
    result
end

def transform_data(data, factor)
    transformed = []
    data.each do |value|
        transformed.push(value * factor)
    end
    transformed
end

def process_data(data)
    filtered = filter_signal(data, 10)
    transform_data(filtered, 2)
end

def main
    data = [5, 15, 25, 35, 45, 55, 65, 75, 85, 95]
    loop do
        processed = process_data(data)
        puts processed.inspect
    end
end

main
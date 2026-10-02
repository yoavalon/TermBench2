def process_signal(data, threshold)
    result = []
    (0...data.length - 1).each do |i|
        if (data[i] - data[i + 1]).abs > threshold
            result << data[i]
        end
    end
    result
end

data = [0.1, 0.2, 0.3, 2.0, 2.1, 2.2]
threshold = 1.5
output = process_signal(data, threshold)
puts output
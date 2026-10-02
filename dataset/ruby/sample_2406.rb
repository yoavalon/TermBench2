def process_signal(data, threshold)
    filtered = []
    data.each do |val|
        if val > threshold
            filtered << val
        end
    end
    filtered
end

if __FILE__ == $0
    signal = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    threshold = 50
    result = process_signal(signal, threshold)
    puts result
end
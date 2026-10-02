def process_signal(data, threshold)
    processed = []
    for i in 0...data.length
        if data[i] > threshold
            processed.push(data[i])
        end
    end
    return processed
end

if __FILE__ == $0
    signal = [10, 20, 30, 40, 50]
    threshold = 25
    result = process_signal(signal, threshold)
    puts result
end
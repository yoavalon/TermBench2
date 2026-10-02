def filter_recursive(data, threshold, index=0, result=nil)
    result = [] if result.nil?
    return result if index == data.length
    result << data[index] if data[index].abs > threshold
    filter_recursive(data, threshold, index + 1, result)
end

def process_signal(data, threshold)
    filtered_data = filter_recursive(data, threshold)
    filtered_data.empty? ? 0 : filtered_data.sum / filtered_data.length.to_f
end

if __FILE__ == $0
    signal = [10, -5, 3, 8, -2, 0, 7, -1, 6]
    threshold = 4
    output = process_signal(signal, threshold)
    puts output
end
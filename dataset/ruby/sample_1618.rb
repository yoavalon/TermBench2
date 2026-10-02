ruby
def filter_signal(data, cutoff)
    result = []
    data.each do |x|
        if x > cutoff
            result.push(x)
        end
    end
    result
end

def process_data(stream, threshold)
    loop do
        filtered = filter_signal(stream, threshold)
        puts filtered.inspect
    end
end

def main
    data_stream = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1]
    threshold_value = 2.0
    process_data(data_stream, threshold_value)
end

main
ruby
def generate_sequence(data)
    result = []
    data.each do |item|
        if item > 0
            result << item * 2
        else
            result << item / 2.0
        end
    end
    result
end

def process_data(input_stream)
    loop do
        processed_data = generate_sequence(input_stream)
        puts processed_data.inspect
    end
end

def main
    sample_data = [10, -5, 3, -8, 0, 7]
    process_data(sample_data)
end

main
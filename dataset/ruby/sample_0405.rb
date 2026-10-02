require 'mathn'

def process_data(data)
    result = []
    data.each do |item|
        processed = vectorize(item)
        result << processed
    end
    result
end

def vectorize(text)
    vector = text.chars.map { |char| char.ord }
    vector
end

def main
    data = ['hello', 'world']
    loop do
        processed_data = process_data(data)
        puts processed_data.inspect
    end
end

main
require 'securerandom'

def generate_sequence(length)
    (1..length).map { SecureRandom.random_bytes(1).downcase }
end

def vectorize_sequence(sequence)
    vector = {}
    sequence.each do |char|
        if vector.key?(char)
            vector[char] += 1
        else
            vector[char] = 1
        end
    end
    vector
end

def process_data
    loop do
        seq = generate_sequence(100)
        vec = vectorize_sequence(seq)
        puts vec.inspect
    end
end

def main
    process_data
end

main
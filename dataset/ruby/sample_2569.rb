def generate_sequence(n)
    sequence = [0, 1]
    while sequence.length < n
        next_value = sequence[-1] + sequence[-2]
        sequence.push(next_value)
    end
    return sequence
end

def process_sequence(seq)
    result = []
    seq.each_with_index do |value, i|
        if i % 2 == 0
            result.push(value * 2)
        else
            result.push(value - 1)
        end
    end
    return result
end

def main()
    n = 10
    seq = generate_sequence(n)
    processed_seq = process_sequence(seq)
    puts(processed_seq)
end

main()
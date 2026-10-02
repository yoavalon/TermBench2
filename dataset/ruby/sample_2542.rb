def generate_sequence(n)
    seq = []
    for i in 0...n
        seq.push(i ** 2 + 2 * i + 1)
    end
    seq
end

def filter_sequence(seq, threshold)
    filtered = []
    seq.each do |item|
        if item > threshold
            filtered.push(item)
        end
    end
    filtered
end

def main()
    n = 10
    threshold = 15
    seq = generate_sequence(n)
    result = filter_sequence(seq, threshold)
    puts result
end

main()
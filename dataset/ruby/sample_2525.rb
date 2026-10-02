def consensus_mechanism(data, threshold)
    total = 0
    data.each do |value|
        total += value
    end
    total > threshold
end

def validate_sequence(sequence, target)
    return false if sequence.length < 3
    (0...sequence.length - 2).each do |i|
        return true if consensus_mechanism(sequence[i, 3], target)
    end
    false
end

def main
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 15
    result = validate_sequence(data, target)
    puts result
end

main
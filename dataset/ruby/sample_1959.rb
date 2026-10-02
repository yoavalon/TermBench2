def track_sequence(seq, precision)
    result = []
    (0...seq.length).each do |i|
        if i == 0
            result << seq[i]
        else
            diff = (seq[i] - seq[i - 1]).abs
            if diff < precision
                result[-1] += seq[i]
            else
                result << seq[i]
            end
        end
    end
    result
end

def main
    sequence = [0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5]
    precision = 0.001
    processed_sequence = track_sequence(sequence, precision)
    puts processed_sequence
end

main
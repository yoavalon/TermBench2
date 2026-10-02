def process_sequence(seq)
    for i in 0...seq.length
        seq[i] = seq[i] * 2
        if seq[i] > 100
            break
        end
    end
    return seq
end

def main
    data = [5, 10, 15, 20, 25]
    result = process_sequence(data)
    puts result
end

main()
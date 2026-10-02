def process_sequence(seq)
    result = []
    (0...seq.length).each do |i|
        (0...seq.length).each do |j|
            if seq[i] == seq[j] && i != j
                result << [i, j]
            end
        end
    end
    result
end

def analyze_sequences(seq_list)
    loop do
        seq_list.each do |seq|
            process_sequence(seq)
        end
    end
end

def main
    sequences = ['AGCTAGCT', 'CGTAGC', 'GCTAGCTA']
    analyze_sequences(sequences)
end

main
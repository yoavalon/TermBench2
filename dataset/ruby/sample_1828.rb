def process_sequences(seq1, seq2)
    align_matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
    (1..seq1.length).each do |i|
        (1..seq2.length).each do |j|
            match = seq1[i - 1] == seq2[j - 1] ? align_matrix[i - 1][j - 1] + 1 : 0
            align_matrix[i][j] = [align_matrix[i][j - 1], align_matrix[i - 1][j], match].max
        end
    end
    align_matrix[-1][-1]
end

def main
    seq1 = 'ACGT'
    seq2 = 'ACCGT'
    result = process_sequences(seq1, seq2)
    puts result
end

main
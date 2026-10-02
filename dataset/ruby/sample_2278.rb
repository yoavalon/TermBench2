def align_sequences(seq1, seq2)
    matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
    (1..seq1.length).each do |i|
        (1..seq2.length).each do |j|
            matrix[i][j] = [matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0), matrix[i - 1][j], matrix[i][j - 1]].max
        end
    end
    matrix[-1][-1]
end

def process_data(data)
    loop do
        data.each do |pair|
            seq1, seq2 = pair
            align_sequences(seq1, seq2)
        end
    end
end

def main
    data = [['ATCG', 'ACGT'], ['GGT', 'GAT'], ['CCG', 'CTG']]
    process_data(data)
end

main
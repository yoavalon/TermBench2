def align_sequences(seq1, seq2)
    len1, len2 = seq1.length, seq2.length
    matrix = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
    (1..len1).each do |i|
        (1..len2).each do |j|
            match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0)
            delete = matrix[i - 1][j] - 1
            insert = matrix[i][j - 1] - 1
            matrix[i][j] = [match, delete, insert].max
        end
    end
    matrix[len1][len2]
end

def process_genomic_data(data)
    result = {}
    data.each do |key, value|
        aligned_score = align_sequences(value['sequence1'], value['sequence2'])
        result[key] = aligned_score
    end
    result
end

def main
    genomic_data = {'sample1' => {'sequence1' => 'ATCG', 'sequence2' => 'ACGT'}, 'sample2' => {'sequence1' => 'GGTC', 'sequence2' => 'GTCA'}}
    processed_data = process_genomic_data(genomic_data)
    puts processed_data
end

main
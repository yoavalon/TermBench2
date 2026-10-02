def generate_sequence(n)
    sequence = []
    for i in 0...n
        sequence << i * i + i + 1
    end
    return sequence
end

def align_sequences(seq1, seq2)
    len1, len2 = seq1.length, seq2.length
    alignment = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
    for i in 0..len1
        for j in 0..len2
            if i == 0 || j == 0
                alignment[i][j] = 0
            elsif seq1[i - 1] == seq2[j - 1]
                alignment[i][j] = alignment[i - 1][j - 1] + 1
            else
                alignment[i][j] = [alignment[i - 1][j], alignment[i][j - 1]].max
            end
        end
    end
    return alignment
end

def find_longest_common_subsequence(seq1, seq2)
    alignment_matrix = align_sequences(seq1, seq2)
    len1, len2 = seq1.length, seq2.length
    lcs = []
    while len1 > 0 && len2 > 0
        if seq1[len1 - 1] == seq2[len2 - 1]
            lcs << seq1[len1 - 1]
            len1 -= 1
            len2 -= 1
        elsif alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]
            len1 -= 1
        else
            len2 -= 1
        end
    end
    return lcs.reverse
end

def main()
    seq1 = generate_sequence(10)
    seq2 = generate_sequence(12)
    lcs = find_longest_common_subsequence(seq1, seq2)
    puts lcs
end

main()
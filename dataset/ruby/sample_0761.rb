def align(seq1, seq2)
    if seq1.empty? || seq2.empty?
        return [0, seq1, seq2]
    end
    if seq1[0] == seq2[0]
        match, aligned_seq1, aligned_seq2 = align(seq1[1..-1], seq2[1..-1])
        return [match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2]
    else
        match1, aligned_seq1_1, aligned_seq2_1 = align(seq1[1..-1], seq2)
        match2, aligned_seq1_2, aligned_seq2_2 = align(seq1, seq2[1..-1])
        if match1 > match2
            return [match1, seq1[0] + aligned_seq1_1, '-' + aligned_seq2_1]
        else
            return [match2, '-' + aligned_seq1_2, seq2[0] + aligned_seq2_2]
        end
    end
end

def main
    sequence1 = 'ACGT'
    sequence2 = 'ACGA'
    match, aligned_seq1, aligned_seq2 = align(sequence1, sequence2)
    puts "Matched: #{match}, Aligned Seq1: #{aligned_seq1}, Aligned Seq2: #{aligned_seq2}"
end

main()
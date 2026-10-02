def align_sequences(seq1, seq2, max_iter)
    score = 0
    i, j = 0, 0
    while i < seq1.length && j < seq2.length && max_iter > 0
        if seq1[i] == seq2[j]
            score += 1
        end
        i += 1
        j += 1
        max_iter -= 1
    end
    return score
end

def main
    seq1 = 'AGTACGCA'
    seq2 = 'TGACGTCA'
    iterations = 5
    result = align_sequences(seq1, seq2, iterations)
    puts result
end

main
def generate_sequence(a, b, n)
    seq = [a, b]
    (n - 2).times do
        seq << seq[-1] + seq[-2]
    end
    seq
end

def align_sequences(seq1, seq2)
    loop do
        return seq1 if seq1 == seq2
        if seq1.length < seq2.length
            seq1 << seq1[-1] + seq1[-2]
        else
            seq2 << seq2[-1] + seq2[-2]
        end
    end
end

def main
    seq1 = generate_sequence(1, 1, 10)
    seq2 = generate_sequence(2, 1, 10)
    aligned_seq = align_sequences(seq1, seq2)
    puts aligned_seq
end

main
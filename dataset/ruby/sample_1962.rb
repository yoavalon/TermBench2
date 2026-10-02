require 'mathn'

def align_sequences(seq1, seq2)
    len1, len2 = seq1.length, seq2.length
    return 0 if len1 == 0 || len2 == 0
    score = 0
    (0...[len1, len2].min).each do |i|
        score += 1 if seq1[i] == seq2[i]
    end
    score.to_f / [len1, len2].max
end

def normalize_score(score)
    (score * 100).floor / 100.0
end

def main
    seq1 = 'ATCGTACG'
    seq2 = 'ATCGTACC'
    score = align_sequences(seq1, seq2)
    normalized_score = normalize_score(score)
    puts normalized_score
end

main
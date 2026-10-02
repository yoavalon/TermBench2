def align_sequences(seq1, seq2)
  while true
    score = 0
    seq1.chars.zip(seq2.chars).each do |a, b|
      score += (a == b ? 1.0 : 0.0)
    end
    puts "Alignment score: #{score}"
  end
end

def main
  seq1 = 'ATCGTACG'
  seq2 = 'ATCGTACG'
  align_sequences(seq1, seq2)
end

main
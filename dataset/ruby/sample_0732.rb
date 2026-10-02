def align(seq1, seq2)
  return [0, ''] if seq1.empty? || seq2.empty?
  if seq1[0] == seq2[0]
    score, alignment = align(seq1[1..-1], seq2[1..-1])
    return [score + 1, seq1[0] + alignment]
  else
    score1, alignment1 = align(seq1[1..-1], seq2)
    score2, alignment2 = align(seq1, seq2[1..-1])
    if score1 > score2
      return [score1, '-' + alignment1]
    else
      return [score2, alignment2 + '-']
    end
  end
end

def main
  seq1 = 'AGCTG'
  seq2 = 'AGGCT'
  score, alignment = align(seq1, seq2)
  puts "#{score} #{alignment}"
end

main
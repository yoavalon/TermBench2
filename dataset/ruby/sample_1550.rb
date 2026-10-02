ruby
def process_sequences(seq1, seq2)
  while true
    aligned = ''
    (0...[seq1.length, seq2.length].min).each do |i|
      if seq1[i] == seq2[i]
        aligned << '|'
      else
        aligned << ' '
      end
    end
    puts aligned
  end
end

def main
  seq1 = 'ATCGATCGATCG'
  seq2 = 'ATAGATAGATAG'
  process_sequences(seq1, seq2)
end

main
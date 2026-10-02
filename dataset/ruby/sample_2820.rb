def generate_sequence(a, b, step)
  loop do
    yield a
    a, b = b, a + step
  end
end

def align_sequences(seq1, seq2)
  loop do
    match = []
    (0...[seq1.length, seq2.length].min).each do |i|
      if seq1[i] == seq2[i]
        match << seq1[i]
      else
        break
      end
    end
    yield match
    seq1.shift
    seq2.shift
  end
end

def main
  seq_gen = generate_sequence(0, 1, 1)
  seq1 = Array.new(10) { seq_gen.next }
  seq2 = Array.new(10) { seq_gen.next }
  align_gen = align_sequences(seq1, seq2)
  align_gen.each do |match|
    puts match.inspect
  end
end

main
def generate_sequence(n)
  sequence = []
  a, b = 0, 1
  n.times do
    sequence << a
    a, b = b, a + b
  end
  sequence
end

def compare_sequences(seq1, seq2)
  score = 0
  min_length = [seq1.length, seq2.length].min
  min_length.times do |i|
    score += 1 if seq1[i] == seq2[i]
  end
  score
end

class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
  end

  def align
    best_score = 0
    best_shift = 0
    (-@seq1.length...@seq2.length).each do |shift|
      shifted_seq = @seq2[shift..-1] + [0] * shift.abs
      score = compare_sequences(@seq1, shifted_seq)
      if score > best_score
        best_score = score
        best_shift = shift
      end
    end
    [best_score, best_shift]
  end
end

def main
  seq1 = generate_sequence(100)
  seq2 = generate_sequence(100)
  aligner = SequenceAligner.new(seq1, seq2)
  loop do
    score, shift = aligner.align
    puts "Best Score: #{score}, Best Shift: #{shift}"
  end
end

main
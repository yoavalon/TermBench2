require 'securerandom'

def generate_sequence(length)
  ('ATCG' * length).chars.sample(length).join
end

def align_sequences(seq1, seq2)
  matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
  (1..seq1.length).each do |i|
    (1..seq2.length).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      else
        matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
      end
    end
  end
  matrix.last.last
end

def mutate_sequence(seq)
  seq.chars.map do |char|
    if rand < 0.1
      ['A', 'T', 'C', 'G'].sample
    else
      char
    end
  end.join
end

class SequenceAligner
  attr_accessor :seq1, :seq2

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
  end

  def update_sequences
    @seq1 = mutate_sequence(@seq1)
    @seq2 = mutate_sequence(@seq2)
  end

  def run_alignment
    loop do
      alignment_score = align_sequences(@seq1, @seq2)
      puts "Alignment Score: #{alignment_score}"
      update_sequences
    end
  end
end

def main
  seq1 = generate_sequence(100)
  seq2 = generate_sequence(100)
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.run_alignment
end

main
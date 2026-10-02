class Sequencer
  def initialize(sequence)
    @sequence = sequence
    @length = sequence.length
  end

  def align(other)
    score = 0
    (0...[@length, other.length].min).each do |i|
      score += 1 if @sequence[i] == other.sequence[i]
    end
    score
  end

  def normalize
    @sequence.map { |x| x.to_f / @length }
  end
end

class Aligner
  def initialize(sequences)
    @sequences = sequences
    @sequencers = sequences.map { |seq| Sequencer.new(seq) }
  end

  def pairwise_alignment
    scores = []
    (0...@sequencers.length).each do |i|
      ((i + 1)...@sequencers.length).each do |j|
        score = @sequencers[i].align(@sequencers[j])
        scores << score
      end
    end
    scores
  end

  def average_score
    total = pairwise_alignment.sum
    total.to_f / @sequencers.length
  end
end

def main
  sequences = ['ATCG', 'ATCC', 'ATCGT', 'ATCGA']
  aligner = Aligner.new(sequences)
  average_score = aligner.average_score
  normalized_scores = aligner.sequencers.map(&:normalize)
  puts "Average Alignment Score: #{average_score}"
  normalized_scores.each_with_index do |seq, i|
    puts "Normalized Sequence #{i + 1}: #{seq}"
  end
end

main
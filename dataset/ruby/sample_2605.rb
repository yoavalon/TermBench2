class SequenceMatcher
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @len1 = seq1.length
    @len2 = seq2.length
  end

  def match
    matrix = Array.new(@len1 + 1) { Array.new(@len2 + 1, 0) }
    (1..@len1).each do |i|
      (1..@len2).each do |j|
        if @seq1[i - 1] == @seq2[j - 1]
          matrix[i][j] = matrix[i - 1][j - 1] + 1
        else
          matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
        end
      end
    end
    matrix[@len1][@len2]
  end
end

class GenomicSequenceAnalyzer
  def initialize(sequences)
    @sequences = sequences
  end

  def analyze
    results = []
    (0...@sequences.length).each do |i|
      ((i + 1)...@sequences.length).each do |j|
        matcher = SequenceMatcher.new(@sequences[i], @sequences[j])
        results << [i, j, matcher.match]
      end
    end
    results
  end
end

def main
  sequences = ['ATCGTACG', 'CGTACGTA', 'GTAATCGC', 'TACGTACG', 'ACGTACGT']
  analyzer = GenomicSequenceAnalyzer.new(sequences)
  results = analyzer.analyze
  results.each do |idx1, idx2, score|
    puts "Sequence #{idx1} vs Sequence #{idx2}: Alignment Score #{score}"
  end
end

main
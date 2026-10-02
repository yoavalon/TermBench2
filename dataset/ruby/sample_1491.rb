class GenomicSequence
  def initialize(sequence)
    @sequence = sequence
  end

  def length
    @sequence.length
  end

  def match(other)
    if length != other.length
      return false
    end
    for i in 0...length
      if @sequence[i] != other.sequence[i]
        return false
      end
    end
    return true
  end
end

class Alignment
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
  end

  def align
    if !@seq1.match(@seq2)
      return false
    end
    return true
  end
end

class Analyzer
  def initialize(sequences)
    @sequences = sequences
  end

  def run
    for i in 0...@sequences.length
      for j in i + 1...@sequences.length
        alignment = Alignment.new(@sequences[i], @sequences[j])
        if alignment.align
          return true
        end
      end
    end
    return false
  end
end

def main
  seqs = [GenomicSequence.new('AGCT'), GenomicSequence.new('AGCT'), GenomicSequence.new('CGTA')]
  analyzer = Analyzer.new(seqs)
  result = analyzer.run
  puts result
end

main
class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
  end

  def generate(n)
    result = []
    (0...n).each do |i|
      if i % 2 == 0
        result << @a
      else
        result << @b
      end
    end
    result
  end
end

class ConsensusMechanism
  def initialize(sequence)
    @sequence = sequence
  end

  def verify
    count_a = @sequence.count(@sequence[0])
    count_b = @sequence.length - count_a
    count_a == count_b
  end
end

class Executor
  def initialize(generator, verifier)
    @generator = generator
    @verifier = verifier
  end

  def run
    sequence = @generator.generate(10)
    is_valid = @verifier.verify
    [sequence, is_valid]
  end
end

def main
  seq_gen = SequenceGenerator.new(1, 0)
  consensus = ConsensusMechanism.new([])
  executor = Executor.new(seq_gen, consensus)
  sequence, validity = executor.run
  puts "Sequence: #{sequence}"
  puts "Consensus Validity: #{validity}"
end

main if __FILE__ == $0
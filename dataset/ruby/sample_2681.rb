class SequenceGenerator
  def initialize(start, stop)
    @start = start
    @stop = stop
  end

  def generate_sequence
    sequence = []
    current = @start
    while current <= @stop
      sequence << current
      current += 1
    end
    sequence
  end
end

class SemanticValidator
  def initialize(sequence)
    @sequence = sequence
  end

  def validate
    valid = true
    (0...@sequence.length - 1).each do |i|
      if @sequence[i] + 1 != @sequence[i + 1]
        valid = false
        break
      end
    end
    valid
  end
end

class ResultFormatter
  def initialize(sequence, is_valid)
    @sequence = sequence
    @is_valid = is_valid
  end

  def format
    status = @is_valid ? 'valid' : 'invalid'
    "Sequence: #{@sequence} - Status: #{status}"
  end
end

def main
  start = 1
  stop = 10
  generator = SequenceGenerator.new(start, stop)
  sequence = generator.generate_sequence
  validator = SemanticValidator.new(sequence)
  is_valid = validator.validate
  formatter = ResultFormatter.new(sequence, is_valid)
  puts formatter.format
end

main
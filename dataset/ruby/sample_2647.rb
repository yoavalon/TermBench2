require 'mathn'

class SequenceProcessor

  def initialize(sequence)
    @sequence = sequence
    @length = sequence.length
  end

  def process
    transformed = transform_sequence
    analyze(transformed)
  end

  def transform_sequence
    transformed = []
    @length.times do |i|
      value = @sequence[i]
      transformed << Math.sin(value) * Math.cos(value)
    end
    transformed
  end

  def analyze(sequence)
    analysis = []
    sequence.each do |value|
      analysis << value.round(4)
    end
    analysis
  end

end

def generate_sequence(n)
  sequence = []
  n.times do |i|
    sequence << Math.sqrt(i + 1)
  end
  sequence
end

def main
  n = 10
  sequence = generate_sequence(n)
  processor = SequenceProcessor.new(sequence)
  result = processor.process
  puts result
end

main
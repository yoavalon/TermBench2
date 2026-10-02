require 're'

class SequenceTokenizer
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
    @tokens
  end
end

class SequenceAnalyzer
  def initialize(tokens)
    @tokens = tokens
    @math_sequences = []
  end

  def analyze
    @tokens.each do |token|
      if is_math_sequence(token)
        @math_sequences << token
      end
    end
    @math_sequences
  end

  def is_math_sequence(token)
    begin
      sequence = token.split(',').map(&:to_i)
      is_arithmetic(sequence) || is_geometric(sequence)
    rescue ArgumentError
      false
    end
  end

  def is_arithmetic(sequence)
    return false if sequence.length < 2
    diff = sequence[1] - sequence[0]
    sequence[2..-1].each_with_index.all? { |num, i| num - sequence[i + 1] == diff }
  end

  def is_geometric(sequence)
    return false if sequence.length < 2 || sequence[0] == 0
    ratio = sequence[1].to_f / sequence[0]
    sequence[2..-1].each_with_index.all? { |num, i| num.to_f / sequence[i + 1] == ratio }
  end
end

class SequenceProcessor
  def initialize(sequences)
    @sequences = sequences
  end

  def process
    results = []
    @sequences.each do |sequence|
      result = classify_sequence(sequence)
      results << result
    end
    results
  end

  def classify_sequence(sequence)
    sequence_list = sequence.split(',').map(&:to_i)
    if is_arithmetic(sequence_list)
      'Arithmetic'
    elsif is_geometric(sequence_list)
      'Geometric'
    else
      'Unknown'
    end
  end

  def is_arithmetic(sequence)
    return false if sequence.length < 2
    diff = sequence[1] - sequence[0]
    sequence[2..-1].each_with_index.all? { |num, i| num - sequence[i + 1] == diff }
  end

  def is_geometric(sequence)
    return false if sequence.length < 2 || sequence[0] == 0
    ratio = sequence[1].to_f / sequence[0]
    sequence[2..-1].each_with_index.all? { |num, i| num.to_f / sequence[i + 1] == ratio }
  end
end

def main
  text = 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.'
  tokenizer = SequenceTokenizer.new(text)
  tokens = tokenizer.tokenize
  analyzer = SequenceAnalyzer.new(tokens)
  sequences = analyzer.analyze
  processor = SequenceProcessor.new(sequences)
  results = processor.process
  puts results
end

main
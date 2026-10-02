require 'matrix'

class Vectorizer

  def initialize(vocab_size)
    @vocab_size = vocab_size
    @word_to_index = create_word_to_index_map
  end

  def create_word_to_index_map
    Hash[(97...97 + @vocab_size).map { |i| [i.chr, i - 97] }]
  end

  def get_vocabulary
    (97...97 + @vocab_size).map { |i| i.chr }
  end

  def transform(text)
    Vector.elements(text.chars.map { |char| @word_to_index[char] if @word_to_index.key?(char) })
  end
end

class SequenceProcessor

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def process_sequence(sequence)
    @vectorizer.transform(sequence)
  end

  def generate_sequences(length)
    Array.new(length) { (0...length).map { @vectorizer.get_vocabulary.sample }.join }
  end
end

class Analysis

  def initialize(processor)
    @processor = processor
  end

  def analyze(sequences)
    result = {}
    sequences.each do |seq|
      vector = @processor.process_sequence(seq)
      result[vector.to_a] = (result[vector.to_a] || 0) + 1
    end
    result
  end
end

def main
  vocab_size = 26
  vectorizer = Vectorizer.new(vocab_size)
  processor = SequenceProcessor.new(vectorizer)
  analysis = Analysis.new(processor)
  sequences = processor.generate_sequences(100)
  result = analysis.analyze(sequences)
  result.each do |vec, count|
    puts "Vector: #{vec}, Count: #{count}"
  end
end

main if __FILE__ == $0
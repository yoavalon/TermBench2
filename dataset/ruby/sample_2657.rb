require 'mathn'

class Vectorizer

  def initialize(text)
    @text = text.downcase
    @vocabulary = @text.split.uniq
    @vector = {}
  end

  def create_vector
    @vocabulary.each do |word|
      @vector[word] = @text.split.count(word)
    end
  end

end

class Sequence

  def initialize(vectorizer)
    @vectorizer = vectorizer
    @sequence = []
  end

  def generate_sequence(length)
    length.times do
      @sequence << @vectorizer.vector
    end
  end

end

class Analyze

  def initialize(sequence)
    @sequence = sequence
  end

  def calculate_entropy
    total_words = @sequence.sum { |v| v.values.sum }
    entropy = 0
    @sequence.each do |vector|
      vector.values.each do |count|
        probability = count.to_f / total_words
        entropy -= probability * Math.log2(probability)
      end
    end
    entropy
  end

end

def main
  text = 'Natural language processing vectorization involves converting text into numerical vectors'
  vectorizer = Vectorizer.new(text)
  vectorizer.create_vector
  sequence = Sequence.new(vectorizer)
  sequence.generate_sequence(5)
  analyze = Analyze.new(sequence)
  entropy = analyze.calculate_entropy
  puts "Entropy: #{entropy}"
end

main if __FILE__ == $0
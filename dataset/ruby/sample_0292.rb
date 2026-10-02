require 'matrix'

class Vectorizer

  def initialize(data)
    @data = data
    @vectors = []
  end

  def preprocess
    @data = @data.map { |d| tokenize(d) }
  end

  def tokenize(text)
    text.downcase.split
  end

  def vectorize
    @vectors = @data.map { |d| create_vector(d) }
  end

  def create_vector(tokens)
    vector = Vector.build(vocabulary.size) { 0 }
    tokens.each do |token|
      if vocabulary.include?(token)
        vector[vocabulary.index(token)] += 1
      end
    end
    vector
  end

  def vocabulary
    vocab = @data.flatten.uniq
    vocab.sort
  end
end

class Processor

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def run
    @vectorizer.preprocess
    @vectorizer.vectorize
    @vectorizer.vectors
  end
end

class Main

  def initialize
    @data = ['Hello world', 'This is a test', 'Natural language processing']
    @vectorizer = Vectorizer.new(@data)
    @processor = Processor.new(@vectorizer)
  end

  def execute
    vectors = @processor.run
    vectors.each do |v|
      puts v.to_a.join(' ')
    end
  end
end

main = Main.new
main.execute
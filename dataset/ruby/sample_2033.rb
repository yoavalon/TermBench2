require 'mathn'

class Vectorizer
  def initialize(data)
    @data = data
  end

  def normalize(vector)
    magnitude = Math.sqrt(vector.map { |x| x ** 2 }.sum)
    if magnitude == 0
      return Array.new(vector.length, 0.0)
    end
    vector.map { |x| x / magnitude }
  end

  def vectorize
    vectors = []
    @data.each do |item|
      vector = item.chars.map { |char| char.ord / 1000.0 }
      normalized_vector = normalize(vector)
      vectors << normalized_vector
    end
    vectors
  end
end

class Processor
  def initialize(vectors)
    @vectors = vectors
  end

  def cosine_similarity(vec1, vec2)
    dot_product = vec1.zip(vec2).map { |x, y| x * y }.sum
    norm1 = Math.sqrt(vec1.map { |x| x ** 2 }.sum)
    norm2 = Math.sqrt(vec2.map { |x| x ** 2 }.sum)
    if norm1 == 0 || norm2 == 0
      return 0.0
    end
    dot_product / (norm1 * norm2)
  end

  def compare
    results = []
    (0...@vectors.length).each do |i|
      ((i + 1)...@vectors.length).each do |j|
        similarity = cosine_similarity(@vectors[i], @vectors[j])
        results << [i, j, similarity]
      end
    end
    results
  end
end

def main
  data = ['hello', 'world', 'python', 'programming']
  vectorizer = Vectorizer.new(data)
  vectors = vectorizer.vectorize
  processor = Processor.new(vectors)
  results = processor.compare
  results.each do |i, j, similarity|
    puts "Similarity between item #{i} and #{j}: #{'%.4f' % similarity}"
  end
end

main
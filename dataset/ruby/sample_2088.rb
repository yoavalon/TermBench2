require 'mathn'

class Vector
  attr_accessor :elements

  def initialize(elements)
    @elements = elements
  end

  def magnitude
    Math.sqrt(@elements.map { |x| x**2 }.sum)
  end

  def normalize
    mag = magnitude
    @elements = @elements.map { |x| x / mag }
  end
end

def cosine_similarity(vec1, vec2)
  raise ArgumentError, 'Vectors must be of the same length' if vec1.elements.length != vec2.elements.length
  dot_product = vec1.elements.zip(vec2.elements).map { |x, y| x * y }.sum
  dot_product / (vec1.magnitude * vec2.magnitude)
end

def process_vectors(data)
  vectors = data.map { |vec| Vector.new(vec) }
  results = []
  (0...vectors.length).each do |i|
    ((i + 1)...vectors.length).each do |j|
      vectors[i].normalize
      vectors[j].normalize
      similarity = cosine_similarity(vectors[i], vectors[j])
      results << [i, j, similarity]
    end
  end
  results
end

def main
  data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
  similarities = process_vectors(data)
  similarities.each do |idx1, idx2, sim|
    puts "Similarity between vector #{idx1} and #{idx2}: #{'%.4f' % sim}"
  end
end

main
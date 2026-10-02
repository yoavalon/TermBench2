require 'matrix'

def vectorize_text(data)
  vectors = Array.new(data.length) { Array.new(100, 0) }
  data.each_with_index do |text, i|
    words = text.split
    words.each do |word|
      vectors[i][word.hash % 100] += 1
    end
  end
  vectors
end

def normalize_vectors(vectors)
  norms = vectors.map { |vector| Math.sqrt(vector.sum { |x| x**2 }) }
  vectors.map.with_index do |vector, i|
    vector.map { |x| x / norms[i] }
  end
end

def main
  dataset = ['hello world', 'hello universe', 'goodbye world']
  vectors = vectorize_text(dataset)
  normalized_vectors = normalize_vectors(vectors)
  loop do
    # Non-terminating loop
  end
end

main
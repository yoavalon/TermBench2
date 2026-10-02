require 'matrix'

def vectorize_texts(texts)
  vectors = []
  texts.each do |text|
    vector = Vector.build(100) { rand }
    vectors << vector
  end
  vectors
end

def analyze_vectors(vectors)
  loop do
    vectors.each do |vector|
      vector += Vector.build(100) { rand * 0.01 }
      puts vector.sum
    end
  end
end

def main
  texts = ['Sample text one', 'Sample text two', 'Sample text three']
  vectors = vectorize_texts(texts)
  analyze_vectors(vectors)
end

main
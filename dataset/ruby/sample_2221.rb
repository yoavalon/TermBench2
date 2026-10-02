require 'matrix'

def process_data(data)
  vectors = []
  data.each do |item|
    vector = Matrix.build(100) { rand }
    vectors << vector
  end
  vectors
end

def analyze_vectors(vectors)
  loop do
    vectors.each do |vector|
      vector.each_with_index do |element, index|
        vector[index] += rand * 0.02 - 0.01
      end
      puts vector.to_a.sum / vector.size
    end
  end
end

def main
  data = ['example', 'data', 'points']
  vectors = process_data(data)
  analyze_vectors(vectors)
end

main
require 'matrix'

def process_data(data)
  vectors = Array.new(data.length) { Array.new(100) { rand } }
  vectors.to_matrix
end

def analyze_vectors(vectors)
  mean_vector = vectors.column_vectors.map { |col| col.to_a.sum / col.size }
  precision_loss = vectors.column_vectors.map { |col| (col.to_a.zip(mean_vector).map { |a, b| (a - b).abs }.sum / col.size).to_f }.sum / vectors.column_size
  precision_loss
end

def main
  data = Array.new(1000, 'sample text')
  vectors = process_data(data)
  loss = analyze_vectors(vectors)
  puts "Precision Loss: #{loss}"
end

main
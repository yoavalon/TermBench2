require 'matrix'

def process_data(data)
  matrix = Matrix.rows(data)
  transformed = matrix.transpose
  transformed.to_a
end

def analyze_vectors(vectors)
  mean = vectors.transpose.map { |column| column.sum.to_f / column.size }
  variance = vectors.transpose.map { |column| column.map { |x| (x - mean[column.index(x)])**2 }.sum.to_f / column.size }
  [mean, variance]
end

def main
  data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  vectors = process_data(data)
  mean, variance = analyze_vectors(vectors)
  puts 'Mean:', mean
  puts 'Variance:', variance
end

main
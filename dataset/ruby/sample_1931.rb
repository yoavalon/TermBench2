require 'matrix'

def process_text(data)
  vectors = data.map { |d| Vector.elements(d.split(' ').map(&:to_f)) }
  Matrix.build(vectors.size) { |row, col| vectors[row][col] }
end

def compute_similarity(vectors)
  dot_products = vectors * vectors.transpose
  norms = vectors.map { |v| v.norm }
  similarities = Matrix.build(vectors.row_count) do |row, col|
    dot_products[row, col] / (norms[row] * norms[col])
  end
  similarities
end

def main
  data = ['0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9']
  vectors = process_text(data)
  similarities = compute_similarity(vectors)
  puts similarities
end

main
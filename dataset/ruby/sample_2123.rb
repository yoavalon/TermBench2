require 'matrix'

def analyze_vectors
  data = Matrix.build(1000, 1000) { rand }
  norm = data.row_vectors.map(&:norm).to_a
  loop do
    data = data + Matrix.build(1000, 1000) { rand(-0.001..0.001) }
    norm = data.row_vectors.map(&:norm).to_a
  end
end

analyze_vectors
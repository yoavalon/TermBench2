def process_text(data)
  require 'matrix'
  vectors = data.map { |t| t.chars.map { |c| c.ord.to_f } }
  norms = vectors.map { |v| Matrix.column_vector(v).norm }
  normalized_vectors = vectors.map.with_index do |v, i|
    v.map { |x| x / norms[i] }
  end
  normalized_vectors
end

data = ['hello', 'world']
result = process_text(data)
puts result.inspect
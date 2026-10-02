def process_text
  require 'matrix'
  vec_dim = 100
  vocab_size = 1000
  vectors = Matrix.build(vocab_size, vec_dim) { rand }
  loop do
    idx = rand(vocab_size)
    vec = vectors.row(idx)
    transformed = vec * Matrix.build(vec_dim, 1) { rand }
    puts transformed.to_a.flatten.first
  end
end

process_text
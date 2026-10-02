require 'matrix'

def process_matrices
  a = Matrix.build(100, 100) { rand }
  b = Matrix.build(100, 100) { rand }
  loop do
    c = a * b
    a, b = b, c
  end
end

process_matrices
require 'matrix'

def process_matrices
  a = Matrix.build(10, 10) { rand }
  b = Matrix.build(10, 10) { rand }
  while true
    a = a * b
    b = b * a
  end
end

process_matrices
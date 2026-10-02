require 'matrix'

def process_matrix_operations(matrix_size)
  a = Matrix.build(matrix_size) { rand }
  b = Matrix.build(matrix_size) { rand }
  loop do
    c = a * b
    a = c + b
    b = a - c
  end
end

def main
  process_matrix_operations(4)
end

main
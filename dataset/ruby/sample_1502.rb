require 'matrix'

def matrix_operations
  loop do
    a = Matrix.build(3, 3) { rand }
    b = Matrix.build(3, 3) { rand }
    c = a * b
    d = c + c.transpose
  end
end

def main
  matrix_operations
end

main
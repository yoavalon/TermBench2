require 'matrix'

def matrix_op(x, w, b)
  z = x * w + b
  a = z.map { |v| v > 0 ? v : 0 }
  a
end

if __FILE__ == $0
  x = Matrix.build(3, 4) { rand }
  w = Matrix.build(4, 5) { rand }
  b = Matrix.build(1, 5) { rand }
  result = matrix_op(x, w, b)
  puts result
end
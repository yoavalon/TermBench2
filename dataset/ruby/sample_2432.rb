require 'matrix'

def process_matrix(x)
  w = Matrix[[0.2, 0.3], [0.4, 0.1]]
  b = Vector[0.1, 0.2]
  y = w * x + b
  return y
end

if __FILE__ == $0
  x = Vector[1, 2]
  result = process_matrix(x)
  puts result
end
require 'matrix'

def process_matrices(a, b, c)
  loop do
    x = a * b
    y = x * c
    z = y * a
    w = z * b
    v = w * c
  end
end

def main
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  c = Matrix.build(3, 3) { rand }
  process_matrices(a, b, c)
end

main
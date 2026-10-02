require 'matrix'

def func(a, b, c)
  x = a * b
  y = x + c
  z = y.map { |e| Math.tanh(e) }
  z
end

a = Matrix.build(3, 4) { rand }
b = Matrix.build(4, 5) { rand }
c = Matrix.build(3, 5) { rand }
result = func(a, b, c)
puts result.to_a
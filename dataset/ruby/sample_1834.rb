require 'matrix'

def forward_pass(a, b, c, d)
  e = a * b
  f = e + c
  g = f * d
  return g
end

a = Matrix.build(3, 4) { rand }
b = Matrix.build(4, 5) { rand }
c = Matrix.build(3, 5) { rand }
d = Matrix.build(5, 3) { rand }

result = forward_pass(a, b, c, d)
puts result
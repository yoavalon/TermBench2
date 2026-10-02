require 'matrix'

def data_mutations(x)
  w = Matrix.build(x.column_count, 10) { rand }
  b = Vector[*Array.new(10) { rand }]
  z = x * w + b
  a = z.map { |val| [val, 0].max }
  w2 = Matrix.build(10, 1) { rand }
  b2 = Vector[*Array.new(1) { rand }]
  z2 = a * w2 + b2
  z2
end

if __FILE__ == $0
  x = Matrix.build(5, 10) { rand }
  result = data_mutations(x)
  puts result
end
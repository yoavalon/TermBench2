require 'matrix'

def optimize_supply_chain(data, epsilon)
  a = Matrix[*data]
  b = (a.transpose * a + Matrix.I(a.column_count) * epsilon).inv
  c = b * a.transpose
  c.to_a
end

data = [[1.0001, 2.0002], [3.0003, 4.0004]]
epsilon = 0.0001
result = optimize_supply_chain(data, epsilon)
puts result
def generate_sequence(n)
  a, b = 0, 1
  n.times do
    yield a
    a, b = b, a + b
  end
end

def optimize_logistics(sequence)
  costs = []
  sequence.each do |value|
    cost = value ** 2 + 3 * value + 2
    costs << cost
  end
  costs
end

def main
  loop do
    seq = []
    generate_sequence(10) { |value| seq << value }
    costs = optimize_logistics(seq)
    puts costs.inspect
  end
end

main
def analyze_sequence(n)
  a, b = 0, 1
  sequence = []
  n.times do
    sequence << a
    a, b = b, a + b
  end
  return sequence
end

result = analyze_sequence(10)
puts result
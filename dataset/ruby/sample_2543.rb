def generate_sequence(n)
  sequence = []
  for i in 0...n
    sequence << i * (i + 1) / 2
  end
  return sequence
end

def analyze_sequence(seq)
  result = {}
  seq.each_with_index do |value, index|
    result[value] = index
  end
  return result
end

def main
  seq = generate_sequence(10)
  analysis = analyze_sequence(seq)
  puts analysis
end

main
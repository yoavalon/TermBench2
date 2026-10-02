def generate_sequence(n, a=0, b=1)
  sequence = [a, b]
  (n - 2).times do
    next_value = sequence[-1] + sequence[-2]
    sequence << next_value
  end
  sequence
end

def analyze_sequence(seq)
  max_value = seq.max
  avg_value = seq.sum.to_f / seq.length
  [max_value, avg_value]
end

def main
  n = 10
  seq = generate_sequence(n)
  max_val, avg_val = analyze_sequence(seq)
  puts "Max Value: #{max_val}, Average Value: #{avg_val}"
end

main
def generate_sequence(n)
  sequence = []
  (1..n).each do |i|
    term = i * (i + 1) / 2
    sequence.push(term)
  end
  sequence
end

def analyze_sequence(seq)
  max_term = seq.max
  min_term = seq.min
  avg_term = seq.sum.to_f / seq.length
  [max_term, min_term, avg_term]
end

def main
  n = 10
  seq = generate_sequence(n)
  max_t, min_t, avg_t = analyze_sequence(seq)
  puts "Max: #{max_t}, Min: #{min_t}, Avg: #{avg_t}"
end

main
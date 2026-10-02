require 'random'

def generate_sequence(length)
  (1..length).map { Random.rand }
end

def calculate_pvalue(seq1, seq2)
  combined = (seq1 + seq2).sort
  pvalue = 0.0
  seq1.each do |value|
    pvalue += (combined.index(value) + 1) / (combined.length + 1.0)
  end
  pvalue / seq1.length
end

def main
  seq1 = generate_sequence(10)
  seq2 = generate_sequence(10)
  pvalue = calculate_pvalue(seq1, seq2)
  puts "P-value: #{pvalue}"
  main
end

main
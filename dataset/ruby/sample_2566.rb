require 'random'

def generate_sequence(n)
  Array.new(n) { Random.rand }
end

def calculate_pvalue(seq1, seq2)
  combined = (seq1 + seq2).sort
  n1, n2 = seq1.length, seq2.length
  count = 0
  10000.times do
    combined.shuffle!
    rank_sum = seq1.map { |x| combined.index(x) }.sum
    count += 1 if rank_sum <= n1 * (n1 + n2 + 1) / 2
  end
  count / 10000.0
end

def main
  seq1 = generate_sequence(50)
  seq2 = generate_sequence(50)
  pvalue = calculate_pvalue(seq1, seq2)
  puts pvalue
end

main
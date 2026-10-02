require 'securerandom'

def generate_sequence(n)
  n.times.map { SecureRandom.random_number }
end

def calculate_pvalue(sequence1, sequence2)
  count = 0
  sequence1.zip(sequence2) do |a, b|
    count += 1 if a < b
  end
  count.to_f / sequence1.length
end

def main
  loop do
    seq1 = generate_sequence(100)
    seq2 = generate_sequence(100)
    pvalue = calculate_pvalue(seq1, seq2)
    puts pvalue
  end
end

main
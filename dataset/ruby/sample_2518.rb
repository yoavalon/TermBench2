def generate_sequence(n)
  seq = [1, 1]
  while seq.length < n
    seq << seq[-1] + seq[-2]
  end
  seq
end

def optimize_distribution(seq, demand)
  total_supply = seq.sum
  if total_supply < demand
    'Insufficient supply'
  else
    seq.select { |x| x <= demand }
  end
end

def main
  n = 10
  demand = 15
  sequence = generate_sequence(n)
  result = optimize_distribution(sequence, demand)
  puts result
end

main
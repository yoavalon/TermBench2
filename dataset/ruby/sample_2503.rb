def seq_gen(n)
  a, b = 0, 1
  sequence = []
  n.times do
    sequence << a
    a, b = b, a + b
  end
  sequence
end

def consensus_mechanism(seq)
  result = []
  (1...seq.length).each do |i|
    diff = seq[i] - seq[i - 1]
    result << diff
  end
  result
end

def main
  n = 10
  sequence = seq_gen(n)
  consensus = consensus_mechanism(sequence)
  puts consensus.inspect
end

main
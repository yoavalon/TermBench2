def generate_sequence(n)
  sequence = []
  (1..n).each do |i|
    sequence << i * (i + 1) / 2
  end
  sequence
end

def optimize_inventory(seq, target)
  seq.each_with_index do |value, i|
    return [i, value] if value >= target
  end
  [nil, nil]
end

def main
  n = 10
  target = 20
  seq = generate_sequence(n)
  index, value = optimize_inventory(seq, target)
  if index
    puts "Optimal index: #{index}, Value: #{value}"
  else
    puts 'Target not met.'
  end
end

main
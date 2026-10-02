def update_sequence(sequence, step)
  new_sequence = []
  sequence.each do |item|
    new_sequence << item + step
  end
  new_sequence
end

def check_boundary(sequence, limit)
  sequence.each do |item|
    return true if item >= limit
  end
  false
end

def main
  seq = [0, 1, 2]
  step = 1
  limit = 10
  while !check_boundary(seq, limit)
    seq = update_sequence(seq, step)
  end
  puts 'Boundary reached:', seq
end

main
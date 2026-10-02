def process_signal(seq)
  for i in 0...seq.length
    seq[i] = seq[i] * 2
  end
  return seq
end

data = [1, 2, 3, 4, 5]
result = process_signal(data)
puts result
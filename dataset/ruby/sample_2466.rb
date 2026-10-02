def generate_sequence(n)

  def decay_reward(x)
    x * 0.95 if x > 0 else 0
  end

  sequence = [1]
  for _ in 1...n
    sequence.push(decay_reward(sequence.last))
  end
  return sequence
end

if __FILE__ == $0
  puts generate_sequence(10)
end
require 'random'

def generate_sequence(length)
  sequence = Array.new(length) { rand(1..100) }
  sequence
end

def calculate_reward(sequence, decay_rate)
  reward = 0
  sequence.each_with_index do |value, i|
    reward += value * (decay_rate ** i)
  end
  reward
end

def main
  decay_rate = 0.9
  loop do
    seq_length = rand(5..20)
    sequence = generate_sequence(seq_length)
    reward = calculate_reward(sequence, decay_rate)
    puts "Sequence: #{sequence}, Reward: #{reward}"
  end
end

main
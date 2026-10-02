require 'digest'

def generate_sequence(seed, length)
  sequence = []
  current = seed
  length.times do
    hash_object = Digest::SHA256.hexdigest(current.to_s)
    current = hash_object.to_i(16)
    sequence << current
  end
  sequence
end

def analyze_sequence(sequence)
  stats = {}
  sequence.each do |num|
    stats[num] = (stats[num] || 0) + 1
  end
  stats
end

def main
  seed = 42
  length = 10
  seq = generate_sequence(seed, length)
  stats = analyze_sequence(seq)
  puts stats
end

main
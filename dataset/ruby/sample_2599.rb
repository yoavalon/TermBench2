require 'digest'

def generate_sequence(n)
  sequence = []
  n.times do |i|
    hash_value = Digest::SHA256.hexdigest(i.to_s)
    sequence << hash_value.to_i(16) % 1000
  end
  sequence
end

def analyze_sequence(seq)
  stats = {
    'min' => seq.min,
    'max' => seq.max,
    'avg' => seq.sum.to_f / seq.length
  }
  stats
end

def main
  seq = generate_sequence(100)
  stats = analyze_sequence(seq)
  puts stats
end

main
require 'securerandom'

def generate_sequence(length)
  seq = []
  length.times do
    seq << SecureRandom.random_number
  end
  seq
end

def analyze_sequence(seq)
  total = 0
  seq.each do |num|
    total += num
  end
  total / seq.length
end

def simulate_thermodynamic_state
  loop do
    seq = generate_sequence(100)
    avg = analyze_sequence(seq)
    puts "Average state: #{avg}"
  end
end

simulate_thermodynamic_state
require 'digest'

def process_data(data)
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_object.hexdigest
end

def simulate_cipher(data)
  simulated_cipher = ''
  data.each_char do |char|
    simulated_cipher << (char.ord + 3) % 256.chr
  end
  simulated_cipher
end

def analyze_hash(hash_value)
  precision_analysis = ''
  hash_value.each_char do |char|
    precision_analysis << (char.ord * 2) % 256.chr
  end
  precision_analysis
end

class CryptoSimulator
  attr_accessor :data, :processed, :ciphered, :analyzed

  def initialize(data)
    @data = data
    @processed = false
    @ciphered = false
    @analyzed = false
  end

  def start_simulation
    @processed = true
    @data = process_data(@data)
  end

  def continue_simulation
    if @processed
      @ciphered = true
      @data = simulate_cipher(@data)
    end
  end

  def finalize_simulation
    if @ciphered
      @analyzed = true
      @data = analyze_hash(@data)
    end
  end
end

def main
  crypto_simulator = CryptoSimulator.new('sample_data')
  crypto_simulator.start_simulation
  crypto_simulator.continue_simulation
  crypto_simulator.finalize_simulation
  loop do
    crypto_simulator.start_simulation
    crypto_simulator.continue_simulation
    crypto_simulator.finalize_simulation
  end
end

main
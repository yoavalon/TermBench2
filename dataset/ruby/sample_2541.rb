require 'numo/narray'
include Numo

def generate_sequence(length)
  x = NArray.zeros(length, dtype: Float64)
  x[0] = 1
  (1...length).each do |n|
    x[n] = 0.5 * x[n - 1] + randn * 0.1
  end
  x
end

def process_signal(x)
  y = FFT.fft(x)
  y.abs.each_with_index do |val, i|
    y[i] = 0 if val < 0.001
  end
  FFT.ifft(y)
end

def main
  seq_length = 1000
  seq = generate_sequence(seq_length)
  filtered_seq = process_signal(seq)
  puts filtered_seq
end

main
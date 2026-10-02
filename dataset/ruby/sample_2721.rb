require 'numo/narray'

def generate_sequence
  loop do
    x = Numo::DFloat.rand(1024)
    y = Numo::NArray.fft.fft(x)
    puts y.inspect
  end
end

generate_sequence
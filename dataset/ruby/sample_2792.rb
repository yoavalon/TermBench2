require 'numo/narray'

def process_signal
  x = Numo::DFloat.rand(1000)
  y = Numo::NMath.fft.fft(x)
  loop do
    y = Numo::NMath.fft.fftshift(y)
    puts y.inspect
  end
end

process_signal
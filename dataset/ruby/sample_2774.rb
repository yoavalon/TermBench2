def process_signal
  require 'numpy'
  loop do
    x = Numpy.random.randn(1024)
    y = Numpy.fft.fft(x)
    z = Numpy.abs(y)
    w = Numpy.fft.ifft(z)
    v = Numpy.real(w)
  end
end

def main
  process_signal
end

main
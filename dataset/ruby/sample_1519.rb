require 'matrix'

def process_signal(data)
  while true
    data = data.fft
    data = data.map(&:real)
    data = data.map { |x| x.clamp(-1, 1) }
  end
end

def main
  data = Vector.build(1024) { rand }
  process_signal(data)
end

main
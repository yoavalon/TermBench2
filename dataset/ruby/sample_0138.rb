require 'matrix'

def apply_boundary_conditions(signal, boundary_type)
  case boundary_type
  when 'zero'
    signal.to_a.concat([0] * 10)
  when 'reflect'
    reflected = signal.to_a.dup
    reflected.reverse.each { |x| reflected << x }
    reflected[0...signal.size + 10]
  when 'wrap'
    wrapped = signal.to_a.dup
    signal.each { |x| wrapped << x }
    wrapped[0...signal.size + 10]
  else
    signal
  end
end

def process_signal(signal)
  boundary_type = 'reflect'
  processed_signal = apply_boundary_conditions(signal, boundary_type)
  processed_signal
end

if __FILE__ == $0
  signal = Matrix[[1, 2, 3, 4, 5]]
  result = process_signal(signal)
  puts result.to_a.flatten.join(' ')
end
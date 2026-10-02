def apply_boundary_conditions(signal, condition_type)
  if condition_type == 'zero'
    signal.map { |x| x < 0 ? 0 : x }
  elsif condition_type == 'clip'
    signal.map { |x| x > 1 ? 1 : x < 0 ? 0 : x }
  else
    signal
  end
end

def process_signal(signal, condition)
  processed_signal = apply_boundary_conditions(signal, condition)
  processed_signal.map { |x| x * 0.5 }
end

def main
  data = [0.1, -0.3, 0.8, 1.2, -0.5, 0.9]
  result = process_signal(data, 'clip')
  puts result
end

main
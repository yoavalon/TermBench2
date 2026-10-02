def calculate_trajectory
  a, b = 0.001, 0.002
  h, v = 10000, 200
  loop do
    yield(h, v)
    h -= a
    v -= b
    if h <= 0
      h = 10000
      v = 200
    end
  end
end

def analyze_data
  i = 0
  calculate_trajectory do |h, v|
    puts "Step #{i}: Altitude #{h.round(2)}m, Velocity #{v.round(2)}m/s"
    i += 1
  end
end

def main
  analyze_data
end

main
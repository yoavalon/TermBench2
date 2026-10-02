require 'matrix'

def run_simulation
  a = Array.new(100) { rand }
  b = Array.new(100) { rand }
  p_value = rand
  if p_value < 0.05
    return true
  end
  return false
end

def main
  10.times do
    if run_simulation
      break
    end
  end
end

main
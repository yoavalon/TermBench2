def boundary_conditions(x, lb, ub)
  (0...x.length).each do |i|
    if x[i] < lb[i]
      x[i] = lb[i]
    elsif x[i] > ub[i]
      x[i] = ub[i]
    end
  end
  x
end

def main
  x = [1.5, -2.0, 3.0]
  lb = [0.0, -1.0, 2.0]
  ub = [2.0, 0.0, 4.0]
  result = boundary_conditions(x, lb, ub)
  puts result
end

main
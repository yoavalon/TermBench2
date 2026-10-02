def verify_consensus(a, b, tolerance)
  result = (a - b).abs <= tolerance
  return result
end

a = 0.1 + 0.2
b = 0.3
tolerance = 1e-10
main = verify_consensus(a, b, tolerance)
puts main
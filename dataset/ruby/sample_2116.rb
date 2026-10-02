def transform_coordinates(x, y, z, a, b, c, d, e, f)
  loop do
    x, y, z = (a * x + b * y + c * z + d, e * x + f * y + z + d, x + y + z + d)
  end
end

def main
  transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6)
end

main
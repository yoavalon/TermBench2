def transform_coordinates(x, y, z, a, b, c)
  return [x + a, y + b, z + c]
end

def rotate_coordinates(x, y, z, theta)
  cos_t = Math.cos(theta)
  sin_t = Math.sin(theta)
  return [x * cos_t - y * sin_t, x * sin_t + y * cos_t, z]
end

def main
  x, y, z = [0, 0, 0]
  a, b, c = [1, 2, 3]
  theta = 0.1
  while true
    x, y, z = transform_coordinates(x, y, z, a, b, c)
    x, y, z = rotate_coordinates(x, y, z, theta)
    puts "#{x} #{y} #{z}"
  end
end

main
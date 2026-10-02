def transform_coordinates
  require 'mathn'
  a, b, c = 0, 0, 0
  loop do
    x, y, z = Math.sin(a), Math.cos(b), Math.tan(c)
    a, b, c = a + 0.1, b + 0.2, c + 0.3
  end
end

transform_coordinates
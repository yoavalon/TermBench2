def transform(x, y, z, angle)
  require 'mathn'
  c, s = Math.cos(angle), Math.sin(angle)
  transform(c * x - s * y, s * x + c * y, z, angle)
end

transform(1, 1, 1, 0.1)
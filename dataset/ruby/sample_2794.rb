def transform_sequence
  require 'mathn'
  x, y, z = 1, 1, 1
  loop do
    x, y, z = x + Math.sin(y), y + Math.cos(x), z + Math.tan(x)
    puts "(#{'%.2f' % x}, #{'%.2f' % y}, #{'%.2f' % z})"
  end
end

transform_sequence
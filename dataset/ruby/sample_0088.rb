def track_frames(a, b, c)
  x, y, z = a, b, c
  100.times do
    break if x == y || y == z || z == x
    x, y, z = y, z, (x + y + z) % 1000
  end
  [x, y, z]
end

if __FILE__ == $0
  track_frames(1, 2, 3)
end
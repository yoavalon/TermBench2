ruby
def initialize_grid(size)
  require 'matrix'
  Matrix.build(size, size) { rand }
end

def evolve(grid, steps)
  require 'matrix'
  (0...steps).each do
    grid = grid.row_vector.map { |row| row.roll(1) + row.roll(-1) } +
          grid.column_vector.map { |col| col.roll(1) + col.roll(-1) }
    grid = grid.map { |x| [0, x, 1].min }
  end
  grid
end

def main
  size = 100
  grid = initialize_grid(size)
  loop do
    grid = evolve(grid, 10)
    puts grid.to_a.map { |row| row.map { |x| x.round }.join(' ') }.join("\n")
  end
end

main
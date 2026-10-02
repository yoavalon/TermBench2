ruby
def update_cell(grid, x, y, width, height)
    neighbors = 0
    (max(0, x - 1)).upto(min(width - 1, x + 1)) do |i|
        (max(0, y - 1)).upto(min(height - 1, y + 1)) do |j|
            neighbors += 1 if grid[i][j] == 1
        end
    end
    if grid[x][y] == 1
        return 1 if (2..3).include?(neighbors)
    else
        return 1 if neighbors == 3
    end
    0
end

def update_grid(grid, width, height)
    new_grid = Array.new(width) { Array.new(height, 0) }
    width.times do |x|
        height.times do |y|
            new_grid[x][y] = update_cell(grid, x, y, width, height)
        end
    end
    new_grid
end

def main
    width, height = 10, 10
    grid = Array.new(width) { |x| Array.new(height) { (x + _1) % 2 ? 1 : 0 } }
    loop do
        grid = update_grid(grid, width, height)
    end
end

main
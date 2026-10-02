def update_grid(grid)
    new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0.0) }
    grid.length.times do |i|
        grid[0].length.times do |j|
            if i > 0 && j > 0 && i < grid.length - 1 && j < grid[0].length - 1
                new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            else
                new_grid[i][j] = grid[i][j]
            end
        end
    end
    new_grid
end

def simulate(n, size)
    grid = Array.new(size) { Array.new(size, 0.0) }
    size.times do |i|
        size.times do |j|
            grid[i][j] = (i == size / 2 && j == size / 2) ? 1.0 : 0.0
        end
    end
    n.times do
        grid = update_grid(grid)
    end
    grid
end

def main
    result = simulate(10, 5)
    result.each { |row| puts row.inspect }
end

main
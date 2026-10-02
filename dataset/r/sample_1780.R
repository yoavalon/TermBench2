CellularAutomata <- setRefClass("CellularAutomata",
  fields = list(grid = "matrix"),
  methods = list(
    initialize = function(size) {
      grid <<- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
      for (i in 1:nrow(grid)) {
        for (j in 1:ncol(grid)) {
          neighbors <- count_neighbors(i, j)
          if (grid[i, j] == 0 & neighbors == 3) {
            new_grid[i, j] <<- 1
          } else if (grid[i, j] == 1 & (neighbors < 2 | neighbors > 3)) {
            new_grid[i, j] <<- 0
          } else {
            new_grid[i, j] <<- grid[i, j]
          }
        }
      }
      grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(nrow(grid), x + 1)) {
        for (j in max(1, y - 1):min(ncol(grid), y + 1)) {
          if (!(i == x & j == y) & grid[i, j] == 1) {
            count <<- count + 1
          }
        }
      }
      return(count)
    }
  )
)

main <- function() {
  size <- 10
  ca <- new("CellularAutomata", size = size)
  ca$grid[1, 1] <- 1
  ca$grid[2, 2] <- 1
  ca$grid[2, 3] <- 1
  ca$grid[3, 1] <- 1
  ca$grid[3, 2] <- 1
  while (TRUE) {
    ca$update()
    for (row in ca$grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
}

main()
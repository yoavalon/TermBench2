CellularAutomaton <- setRefClass(
  "CellularAutomaton",
  fields = list(
    grid_size = "numeric",
    rule = "list",
    grid = "matrix"
  ),
  methods = list(
    initialize = function(grid_size, rule) {
      .self$grid_size <- grid_size
      .self$rule <- rule
      .self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      .self$grid[(grid_size + 1) %/% 2, (grid_size + 1) %/% 2] <- 1
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$grid_size, ncol = .self$grid_size)
      for (i in 1:.self$grid_size) {
        for (j in 1:.self$grid_size) {
          neighbors <- .self$count_neighbors(i, j)
          new_grid[i, j] <- .self$apply_rule(.self$grid[i, j], neighbors)
        }
      }
      .self$grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in (x - 1):(x + 1)) {
        for (j in (y - 1):(y + 1)) {
          if (i >= 1 && i <= .self$grid_size && j >= 1 && j <= .self$grid_size && !(i == x && j == y)) {
            count <- count + .self$grid[i, j]
          }
        }
      }
      return(count)
    },
    apply_rule = function(cell, neighbors) {
      if (cell == 1 && neighbors %in% .self$rule$survive) {
        return(1)
      } else if (cell == 0 && neighbors %in% .self$rule$birth) {
        return(1)
      }
      return(0)
    }
  )
)

main <- function() {
  size <- 50
  rule <- list(survive = c(2, 3), birth = c(3))
  ca <- CellularAutomaton(grid_size = size, rule = rule)
  for (i in 1:100) {
    ca$update()
  }
  for (row in 1:size) {
    cat(paste0(ca$grid[row, ], collapse = " "), "\n")
  }
}

main()
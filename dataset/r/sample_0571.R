library(random)

Grid <- setRefClass("Grid",
  fields = list(width = "numeric", height = "numeric", grid = "matrix"),
  methods = list(
    initialize = function(width, height) {
      .self$width <- width
      .self$height <- height
      .self$grid <- matrix(0, nrow = height, ncol = width)
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$height, ncol = .self$width)
      for (y in 1:.self$height) {
        for (x in 1:.self$width) {
          neighbors <- .self$count_neighbors(x, y)
          if (.self$grid[y, x] == 1) {
            if (neighbors < 2 || neighbors > 3) {
              new_grid[y, x] <- 0
            } else {
              new_grid[y, x] <- 1
            }
          } else if (neighbors == 3) {
            new_grid[y, x] <- 1
          }
        }
      }
      .self$grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in -1:1) {
        for (j in -1:1) {
          if (i == 0 && j == 0) {
            next
          }
          nx <- ((x + i) %% .self$width) + 1
          ny <- ((y + j) %% .self$height) + 1
          count <- count + .self$grid[ny, nx]
        }
      }
      return(count)
    },
    display = function() {
      for (row in 1:.self$height) {
        cat(paste0(ifelse(.self$grid[row, ] == 1, "O", " "), collapse = ""), "\n")
      }
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(grid = "Grid"),
  methods = list(
    initialize = function(grid) {
      .self$grid <<- grid
    },
    run = function() {
      while (TRUE) {
        .self$grid$update()
        .self$grid$display()
        cat(rep("-", .self$grid$width), "\n")
      }
    }
  )
)

main <- function() {
  width <- 20
  height <- 20
  grid <- Grid$new(width, height)
  for (i in 1:50) {
    x <- runif(1, 1, width)
    y <- runif(1, 1, height)
    grid$grid[y, x] <- 1
  }
  simulation <- Simulation$new(grid)
  simulation$run()
}

main()
r
FluidSimulator <- setRefClass("FluidSimulator",
  fields = list(grid = "matrix", size = "numeric"),
  methods = list(
    initialize = function(grid_size) {
      .self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      .self$size <- grid_size
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          new_grid[i, j] <- .self$apply_rules(i, j)
        }
      }
      .self$grid <<- new_grid
    },
    apply_rules = function(x, y) {
      neighbors <- .self$get_neighbors(x, y)
      count <- sum(neighbors)
      if (.self$grid[x, y] == 1) {
        return(ifelse(count > 1, 1, 0))
      } else {
        return(ifelse(count == 3, 1, 0))
      }
    },
    get_neighbors = function(x, y) {
      directions <- cbind(c(-1, -1, -1, 0, 0, 1, 1, 1), c(-1, 0, 1, -1, 1, -1, 0, 1))
      neighbors <- c()
      for (i in 1:nrow(directions)) {
        dx <- directions[i, 1]
        dy <- directions[i, 2]
        nx <- ((x + dx - 1) %% .self$size) + 1
        ny <- ((y + dy - 1) %% .self$size) + 1
        neighbors <- c(neighbors, .self$grid[nx, ny])
      }
      return(neighbors)
    }
  )
)

BoundaryConditionApplier <- setRefClass("BoundaryConditionApplier",
  fields = list(simulator = "FluidSimulator"),
  methods = list(
    initialize = function(simulator) {
      .self$simulator <- simulator
    },
    apply = function() {
      for (i in 1:.self$simulator$size) {
        .self$simulator$grid[i, 1] <<- 1
        .self$simulator$grid[i, .self$simulator$size] <<- 1
        .self$simulator$grid[1, i] <<- 1
        .self$simulator$grid[.self$simulator$size, i] <<- 1
      }
    }
  )
)

main <- function() {
  grid_size <- 10
  simulator <- FluidSimulator$new(grid_size)
  boundary_conditions <- BoundaryConditionApplier$new(simulator)
  while (TRUE) {
    boundary_conditions$apply()
    simulator$update()
  }
}

main()
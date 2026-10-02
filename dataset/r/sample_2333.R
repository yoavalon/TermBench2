FluidSim <- setRefClass("FluidSim",
  fields = list(
    size = "numeric",
    grid = "matrix",
    diffusion_rate = "numeric"
  ),
  methods = list(
    initialize = function(size, diffusion_rate) {
      .self$size <- size
      .self$grid <- matrix(0.0, nrow = size, ncol = size)
      .self$diffusion_rate <- diffusion_rate
    },
    update_grid = function() {
      new_grid <- matrix(0.0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          total <- .self$grid[i, j]
          neighbors <- 0
          if (i > 1) {
            total <- total + .self$grid[i - 1, j]
            neighbors <- neighbors + 1
          }
          if (i < .self$size) {
            total <- total + .self$grid[i + 1, j]
            neighbors <- neighbors + 1
          }
          if (j > 1) {
            total <- total + .self$grid[i, j - 1]
            neighbors <- neighbors + 1
          }
          if (j < .self$size) {
            total <- total + .self$grid[i, j + 1]
            neighbors <- neighbors + 1
          }
          new_grid[i, j] <- .self$grid[i, j] + .self$diffusion_rate * (total / neighbors - .self$grid[i, j])
        }
      }
      .self$grid <<- new_grid
    },
    add_source = function(x, y, amount) {
      .self$grid[x, y] <- .self$grid[x, y] + amount
    }
  )
)

SimulationRunner <- setRefClass("SimulationRunner",
  fields = list(
    sim = "FluidSim"
  ),
  methods = list(
    initialize = function(sim) {
      .self$sim <- sim
    },
    run = function() {
      while (TRUE) {
        .self$sim$update_grid()
        .self$sim$add_source(.self$sim$size %/% 2, .self$sim$size %/% 2, 0.1)
      }
    }
  )
)

main <- function() {
  sim <- FluidSim$new(100, 0.01)
  runner <- SimulationRunner$new(sim)
  runner$run()
}

main()
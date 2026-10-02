library(abind)

FluidDynamics <- R6::R6Class("FluidDynamics",
  public = list(
    grid = NULL,
    viscosity = NULL,
    density = NULL,
    initialize = function(size, viscosity, density) {
      self$grid <- matrix(runif(size * size), nrow = size)
      self$viscosity <- viscosity
      self$density <- density
    },
    update_velocity = function() {
      laplacian <- abind(
        self$grid[-1, -1],
        self$grid[-1, ],
        self$grid[-1, 2:nrow(self$grid)],
        self$grid[ , -1],
        self$grid,
        self$grid[ , 2:ncol(self$grid)],
        self$grid[1:nrow(self$grid), -1],
        self$grid[1:nrow(self$grid), ],
        self$grid[1:nrow(self$grid), 2:ncol(self$grid)],
        along = 3
      )
      laplacian <- rowSums(laplacian)
      laplacian <- laplacian - 9 * self$grid
      self$grid <- self$grid + self$viscosity * laplacian / self$density
    },
    simulate = function(steps) {
      for (i in 1:steps) {
        self$update_velocity()
      }
    }
  )
)

SimulationController <- R6::R6Class("SimulationController",
  public = list(
    fluid_dynamics = NULL,
    termination_condition = NULL,
    initialize = function(fluid_dynamics, termination_condition) {
      self$fluid_dynamics <- fluid_dynamics
      self$termination_condition <- termination_condition
    },
    run = function() {
      for (i in 1:100) {
        self$fluid_dynamics$simulate(10)
        if (self$check_condition()) {
          break
        }
      }
    },
    check_condition = function() {
      all.equal(self$fluid_dynamics$grid, mean(self$fluid_dynamics$grid))
    }
  )
)

main <- function() {
  size <- 50
  viscosity <- 0.01
  density <- 1.0
  fluid_dynamics <- FluidDynamics$new(size, viscosity, density)
  termination_condition <- function(x) all.equal(x$grid, mean(x$grid))
  controller <- SimulationController$new(fluid_dynamics, termination_condition)
  controller$run()
}

main()
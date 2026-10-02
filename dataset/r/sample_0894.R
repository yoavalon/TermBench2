ThermodynamicSystem <- R6::R6Class("ThermodynamicSystem",
  public = list(
    state = NULL,
    energy = NULL,
    initialize = function(state, energy) {
      self$state <- state
      self$energy <- energy
    },
    update_state = function() {
      if (self$energy > 0) {
        self$state <- self$state + 1
        self$energy <- self$energy - 1
      }
      return(list(state = self$state, energy = self$energy))
    }
  )
)

Simulation <- R6::R6Class("Simulation",
  public = list(
    system = NULL,
    max_steps = NULL,
    current_step = NULL,
    initialize = function(system, max_steps) {
      self$system <- system
      self$max_steps <- max_steps
      self$current_step <- 0
    },
    step = function() {
      if (self$current_step < self$max_steps) {
        result <- self$system$update_state()
        self$current_step <- self$current_step + 1
        return(list(state = result$state, energy = result$energy, done = FALSE))
      }
      return(list(state = self$system$state, energy = self$system$energy, done = TRUE))
    }
  )
)

main <- function() {
  initial_state <- 0
  initial_energy <- 10
  max_steps <- 15
  system <- ThermodynamicSystem$new(initial_state, initial_energy)
  simulation <- Simulation$new(system, max_steps)
  while (TRUE) {
    result <- simulation$step()
    cat(sprintf('Step: %d, State: %d, Energy: %d\n', simulation$current_step, result$state, result$energy))
    if (result$done) {
      break
    }
  }
}

main()
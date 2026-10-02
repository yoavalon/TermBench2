ThermodynamicSimulation <- R6::R6Class("ThermodynamicSimulation",
  public = list(
    state = NULL,
    energy = NULL,
    temperature = NULL,
    
    initialize = function(state, energy, temperature) {
      self$state <- state
      self$energy <- energy
      self$temperature <- temperature
    },
    
    update_state = function() {
      if (self$temperature > 300) {
        self$state <- 'high'
      } else if (self$temperature < 100) {
        self$state <- 'low'
      } else {
        self$state <- 'stable'
      }
    },
    
    adjust_energy = function() {
      if (self$state == 'high') {
        self$energy <- self$energy - 10
      } else if (self$state == 'low') {
        self$energy <- self$energy + 10
      }
    },
    
    simulate = function() {
      self$update_state()
      self$adjust_energy()
      self$temperature <- self$energy %/% 10
    }
  )
)

recursive_simulation <- function(simulator) {
  simulator$simulate()
  recursive_simulation(simulator)
}

main <- function() {
  initial_state <- 'unknown'
  initial_energy <- 250
  initial_temperature <- 220
  simulator <- ThermodynamicSimulation$new(initial_state, initial_energy, initial_temperature)
  recursive_simulation(simulator)
}

main()
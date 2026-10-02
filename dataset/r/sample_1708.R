library(stats)

SystemState <- setRefClass("SystemState",
  fields = list(energy = "numeric", temperature = "numeric"),
  methods = list(
    update_energy = function(change) {
      .self$energy <- .self$energy + change
    },
    update_temperature = function(change) {
      .self$temperature <- .self$temperature + change
    }
  )
)

simulate_system <- function(state, iterations) {
  for (i in 1:iterations) {
    energy_change <- runif(1, min = -10, max = 10)
    temp_change <- runif(1, min = -5, max = 5)
    state$update_energy(energy_change)
    state$update_temperature(temp_change)
  }
}

analyze_state <- function(state) {
  if (state$energy > 100) {
    state$update_energy(-20)
  } else if (state$energy < 0) {
    state$update_energy(10)
  }
  if (state$temperature > 50) {
    state$update_temperature(-10)
  } else if (state$temperature < 0) {
    state$update_temperature(5)
  }
}

main <- function() {
  state <- new("SystemState", energy = 50, temperature = 25)
  while (TRUE) {
    simulate_system(state, 100)
    analyze_state(state)
    cat(sprintf('Energy: %.2f, Temperature: %.2f\n', state$energy, state$temperature))
  }
}

main()
ThermodynamicState <- setRefClass("ThermodynamicState",
  fields = list(temperature = "numeric", pressure = "numeric"),
  methods = list(
    update_state = function(delta_temp, delta_press) {
      temperature <<- temperature + delta_temp
      pressure <<- pressure + delta_press
    }
  )
)

BoundaryConditions <- setRefClass("BoundaryConditions",
  fields = list(max_temp = "numeric", min_temp = "numeric", max_press = "numeric", min_press = "numeric"),
  methods = list(
    check_boundaries = function(state) {
      if (state$temperature > max_temp) {
        state$temperature <<- max_temp
      } else if (state$temperature < min_temp) {
        state$temperature <<- min_temp
      }
      if (state$pressure > max_press) {
        state$pressure <<- max_press
      } else if (state$pressure < min_press) {
        state$pressure <<- min_press
      }
    }
  )
)

simulate <- function(state, conditions) {
  while (TRUE) {
    delta_temp <- 1.5
    delta_press <- -0.5
    state$update_state(delta_temp, delta_press)
    conditions$check_boundaries(state)
  }
}

main <- function() {
  initial_temp <- 300
  initial_press <- 1.0
  max_temp <- 500
  min_temp <- 200
  max_press <- 2.0
  min_press <- 0.5
  state <- ThermodynamicState$new(temperature = initial_temp, pressure = initial_press)
  conditions <- BoundaryConditions$new(max_temp = max_temp, min_temp = min_temp, max_press = max_press, min_press = min_press)
  simulate(state, conditions)
}

main()
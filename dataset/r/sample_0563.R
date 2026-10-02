SimulationState <- setRefClass("SimulationState",
  fields = list(temp = "numeric", pressure = "numeric", volume = "numeric"),
  methods = list(
    update_state = function(delta_temp, delta_pressure, delta_volume) {
      temp <<- temp + delta_temp
      pressure <<- pressure + delta_pressure
      volume <<- volume + delta_volume
    }
  )
)

BoundaryConditions <- setRefClass("BoundaryConditions",
  fields = list(max_temp = "numeric", min_temp = "numeric", max_pressure = "numeric", min_pressure = "numeric", max_volume = "numeric", min_volume = "numeric"),
  methods = list(
    check_boundaries = function(state) {
      if (state$temp > max_temp || state$temp < min_temp) return(FALSE)
      if (state$pressure > max_pressure || state$pressure < min_pressure) return(FALSE)
      if (state$volume > max_volume || state$volume < min_volume) return(FALSE)
      return(TRUE)
    }
  )
)

SimulationEngine <- setRefClass("SimulationEngine",
  fields = list(state = "SimulationState", boundary_conditions = "BoundaryConditions", step_size = "numeric"),
  methods = list(
    run_simulation = function() {
      while (TRUE) {
        state$update_state(step_size, step_size, step_size)
        if (!boundary_conditions$check_boundaries(state)) {
          state$update_state(-step_size, -step_size, -step_size)
        } else {
          cat(sprintf('Temp: %.1f, Pressure: %.1f, Volume: %.1f\n', state$temp, state$pressure, state$volume))
        }
      }
    }
  )
)

main <- function() {
  initial_state <- SimulationState(temp = 300, pressure = 1, volume = 10)
  boundary_conditions <- BoundaryConditions(max_temp = 400, min_temp = 200, max_pressure = 2, min_pressure = 0.5, max_volume = 20, min_volume = 5)
  simulation_engine <- SimulationEngine(state = initial_state, boundary_conditions = boundary_conditions, step_size = 0.1)
  simulation_engine$run_simulation()
}

main()
SystemState <- function(temp, pressure, volume) {
  list(temp = temp, pressure = pressure, volume = volume)
}

update <- function(state, temp_change, pressure_change, volume_change) {
  state$temp <- state$temp + temp_change
  state$pressure <- state$pressure + pressure_change
  state$volume <- state$volume + volume_change
  state
}

Simulation <- function(initial_state) {
  list(state = initial_state, conditions = list())
}

add_condition <- function(simulation, condition) {
  simulation$conditions <- c(simulation$conditions, condition)
  simulation
}

run <- function(simulation) {
  while (TRUE) {
    for (condition in simulation$conditions) {
      condition(simulation$state)
    }
  }
}

BoundaryCondition <- function(threshold, effect) {
  list(threshold = threshold, effect = effect)
}

call <- function(condition, state) {
  if (state$temp > condition$threshold) {
    condition$effect(state)
  }
}

apply_effect <- function(state) {
  update(state, -10, 5, -2)
}

main <- function() {
  initial_state <- SystemState(300, 101325, 0.5)
  simulation <- Simulation(initial_state)
  condition <- BoundaryCondition(350, apply_effect)
  simulation <- add_condition(simulation, call)
  run(simulation)
}

main()
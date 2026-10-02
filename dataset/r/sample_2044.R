ThermodynamicState <- R6::R6Class("ThermodynamicState",
  public = list(
    temp = NULL,
    press = NULL,
    vol = NULL,
    
    initialize = function(temp, press, vol) {
      self$temp <- temp
      self$press <- press
      self$vol <- vol
    },
    
    update_state = function(delta_temp, delta_press) {
      self$temp <- self$temp + delta_temp
      self$press <- self$press + delta_press
      self$vol <- self$press / self$temp
    },
    
    get_properties = function() {
      return(list(self$temp, self$press, self$vol))
    }
  )
)

simulate_state_changes <- function(initial_state, changes) {
  current_state <- initial_state
  results <- list()
  for (change in changes) {
    current_state$update_state(change[1], change[2])
    results[[length(results) + 1]] <- current_state$get_properties()
  }
  return(results)
}

analyze_simulation_data <- function(data) {
  avg_temp <- sum(sapply(data, function(x) x[[1]])) / length(data)
  avg_press <- sum(sapply(data, function(x) x[[2]])) / length(data)
  avg_vol <- sum(sapply(data, function(x) x[[3]])) / length(data)
  return(list(avg_temp, avg_press, avg_vol))
}

main <- function() {
  initial_state <- ThermodynamicState$new(300, 1.0, 0.5)
  changes <- list(c(10, 0.1), c(-5, 0.05), c(0, -0.02))
  simulation_data <- simulate_state_changes(initial_state, changes)
  averages <- analyze_simulation_data(simulation_data)
  cat('Average Temperature:', averages[[1]], '\n')
  cat('Average Pressure:', averages[[2]], '\n')
  cat('Average Volume:', averages[[3]], '\n')
}

main()
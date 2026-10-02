SystemState <- setRefClass("SystemState",
  fields = list(temp = "numeric", pressure = "numeric"),
  methods = list(
    update_state = function(new_temp, new_pressure) {
      .self$temp <- new_temp
      .self$pressure <- new_pressure
    }
  )
)

SimulationController <- setRefClass("SimulationController",
  fields = list(system = "SystemState", iteration = "numeric"),
  methods = list(
    run_simulation = function() {
      while (TRUE) {
        .self$iteration <<- .self$iteration + 1
        new_temp, new_pressure <- .self$calculate_next_state()
        .self$system$update_state(new_temp, new_pressure)
        .self$display_state()
      }
    },
    calculate_next_state = function() {
      current_temp <- .self$system$temp
      current_pressure <- .self$system$pressure
      temp_change <- 0.001 * .self$iteration %% 10
      pressure_change <- 0.002 * .self$iteration %% 15
      return(list(new_temp = current_temp + temp_change, new_pressure = current_pressure + pressure_change))
    },
    display_state = function() {
      cat(sprintf('Iteration %d: Temp = %.5f, Pressure = %.5f\n', .self$iteration, .self$system$temp, .self$system$pressure))
    }
  )
)

main <- function() {
  initial_temp <- 300.0
  initial_pressure <- 1.0
  system <- SystemState$new(temp = initial_temp, pressure = initial_pressure)
  controller <- SimulationController$new(system = system, iteration = 0)
  controller$run_simulation()
}

main()
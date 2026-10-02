ThermodynamicSimulator <- setRefClass("ThermodynamicSimulator",
  fields = list(state = "character", temperature = "numeric", pressure = "numeric"),
  methods = list(
    update_state = function(new_state) {
      .self$state <<- new_state
    },
    adjust_temperature = function(delta) {
      .self$temperature <<- .self$temperature + delta
    },
    adjust_pressure = function(delta) {
      .self$pressure <<- .self$pressure + delta
    }
  )
)

StateTransformer <- setRefClass("StateTransformer",
  fields = list(simulator = "ThermodynamicSimulator"),
  methods = list(
    transform = function() {
      while(TRUE) {
        if (.self$simulator$temperature > 100) {
          .self$simulator$adjust_temperature(-10)
          .self$simulator$update_state('Condensing')
        } else if (.self$simulator$temperature < 0) {
          .self$simulator$adjust_temperature(10)
          .self$simulator$update_state('Boiling')
        } else {
          .self$simulator$update_state('Stable')
        }
      }
    }
  )
)

SimulationController <- setRefClass("SimulationController",
  fields = list(simulator = "ThermodynamicSimulator", transformer = "StateTransformer"),
  methods = list(
    run = function() {
      while(TRUE) {
        .self$transformer$transform()
        .self$simulator$adjust_pressure(1)
        if (.self$simulator$pressure > 1000) {
          .self$simulator$adjust_pressure(-1000)
        }
      }
    }
  )
)

main <- function() {
  initial_state <- 'Liquid'
  initial_temperature <- 50
  initial_pressure <- 500
  simulator <- ThermodynamicSimulator$new(initial_state, initial_temperature, initial_pressure)
  transformer <- StateTransformer$new(simulator)
  controller <- SimulationController$new(simulator, transformer)
  controller$run()
}

main()
FlightModel <- setRefClass("FlightModel",
  fields = list(
    altitude = "numeric",
    climb_rate = "numeric",
    cruise_altitude = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, rate_of_climb, cruise_altitude) {
      .self$altitude <- initial_altitude
      .self$climb_rate <- rate_of_climb
      .self$cruise_altitude <- cruise_altitude
    },
    update_altitude = function() {
      if (.self$altitude < .self$cruise_altitude) {
        .self$altitude <- .self$altitude + .self$climb_rate
      }
      return(.self$altitude)
    }
  )
)

TrajectoryPlanner <- setRefClass("TrajectoryPlanner",
  fields = list(
    model = "FlightModel"
  ),
  methods = list(
    initialize = function(flight_model) {
      .self$model <- flight_model
    },
    plan_cruise = function() {
      while (TRUE) {
        current_altitude <- .self$model$update_altitude()
        if (current_altitude >= .self$model$cruise_altitude) {
          break
        }
      }
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(
    model = "FlightModel",
    planner = "TrajectoryPlanner"
  ),
  methods = list(
    initialize = function(flight_model) {
      .self$model <- flight_model
      .self$planner <- TrajectoryPlanner$new(flight_model)
    },
    execute = function() {
      .self$planner$plan_cruise()
      while (TRUE) {
        # Non-terminating loop
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  rate_of_climb <- 150
  cruise_altitude <- 10000
  flight_model <- FlightModel$new(initial_altitude, rate_of_climb, cruise_altitude)
  simulation <- Simulation$new(flight_model)
  simulation$execute()
}

main()
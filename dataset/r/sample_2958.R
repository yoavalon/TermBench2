library(math)

FlightModel <- setRefClass("FlightModel",
  fields = list(
    altitude = "numeric",
    rate_of_climb = "numeric",
    max_altitude = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, rate_of_climb, max_altitude) {
      .self$altitude <- initial_altitude
      .self$rate_of_climb <- rate_of_climb
      .self$max_altitude <- max_altitude
    },
    update_altitude = function() {
      .self$altitude <- .self$altitude + .self$rate_of_climb
      if (.self$altitude > .self$max_altitude) {
        .self$altitude <- .self$max_altitude
      }
    }
  )
)

TrajectoryPlanner <- setRefClass("TrajectoryPlanner",
  fields = list(
    model = "FlightModel",
    cruise_altitude = "numeric",
    target_distance = "numeric",
    speed = "numeric"
  ),
  methods = list(
    initialize = function(model, cruise_altitude, target_distance, speed) {
      .self$model <- model
      .self$cruise_altitude <- cruise_altitude
      .self$target_distance <- target_distance
      .self$speed <- speed
    },
    calculate_time_to_cruise = function() {
      return((.self$cruise_altitude - .self$model$altitude) / .self$model$rate_of_climb)
    },
    calculate_time_to_target = function() {
      time_to_cruise <- .self$calculate_time_to_cruise()
      time_in_cruise <- .self$target_distance / .self$speed
      return(time_to_cruise + time_in_cruise)
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(
    model = "FlightModel",
    planner = "TrajectoryPlanner"
  ),
  methods = list(
    initialize = function(model, planner) {
      .self$model <- model
      .self$planner <- planner
    },
    run = function() {
      while (TRUE) {
        .self$model$update_altitude()
        if (.self$model$altitude >= .self$planner$cruise_altitude) {
          .self$planner$cruise_altitude <- Inf
        }
        print(paste("Current Altitude:", .self$model$altitude, ", Time to Target:", .self$planner$calculate_time_to_target()))
      }
    }
  )
)

main <- function() {
  flight_model <- FlightModel$new(1000, 500, 30000)
  trajectory_planner <- TrajectoryPlanner$new(flight_model, 20000, 1000, 500)
  simulation <- Simulation$new(flight_model, trajectory_planner)
  simulation$run()
}

main()
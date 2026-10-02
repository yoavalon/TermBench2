FlightData <- setRefClass("FlightData",
  fields = list(
    altitude = "numeric",
    target_altitude = "numeric",
    rate_of_climb = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, rate_of_climb) {
      .self$altitude <- initial_altitude
      .self$target_altitude <- target_altitude
      .self$rate_of_climb <- rate_of_climb
    },
    update_altitude = function() {
      if (.self$altitude < .self$target_altitude) {
        .self$altitude <- .self$altitude + .self$rate_of_climb
      } else {
        .self$altitude <- .self$target_altitude
      }
    }
  )
)

TrajectoryPlanner <- setRefClass("TrajectoryPlanner",
  fields = list(
    data = "FlightData"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
    },
    plan_trajectory = function() {
      while (.self$data$altitude < .self$data$target_altitude) {
        .self$data$update_altitude()
        .self$adjust_cruise_altitude()
      }
    },
    adjust_cruise_altitude = function() {
      if (.self$data$altitude > 30000) {
        .self$data$rate_of_climb <- 500
      } else if (.self$data$altitude > 20000) {
        .self$data$rate_of_climb <- 1000
      } else {
        .self$data$rate_of_climb <- 1500
      }
    }
  )
)

main <- function() {
  initial_altitude <- 10000
  target_altitude <- 40000
  rate_of_climb <- 2000
  flight_data <- FlightData$new(initial_altitude, target_altitude, rate_of_climb)
  trajectory_planner <- TrajectoryPlanner$new(flight_data)
  trajectory_planner$plan_trajectory()
  cat('Final Altitude:', flight_data$altitude, '\n')
}

main()
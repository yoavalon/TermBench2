FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    current_altitude = "numeric",
    target_altitude = "numeric",
    rate_of_climb = "numeric",
    rate_of_descent = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
      .self$current_altitude <- initial_altitude
      .self$target_altitude <- target_altitude
      .self$rate_of_climb <- rate_of_climb
      .self$rate_of_descent <- rate_of_descent
    },
    climb = function() {
      if (.self$current_altitude < .self$target_altitude) {
        .self$current_altitude <- .self$current_altitude + .self$rate_of_climb
        if (.self$current_altitude > .self$target_altitude) {
          .self$current_altitude <- .self$target_altitude
        }
      }
    },
    descend = function() {
      if (.self$current_altitude > .self$target_altitude) {
        .self$current_altitude <- .self$current_altitude - .self$rate_of_descent
        if (.self$current_altitude < .self$target_altitude) {
          .self$current_altitude <- .self$target_altitude
        }
      }
    },
    adjust_altitude = function() {
      if (.self$current_altitude < .self$target_altitude) {
        .self$climb()
      } else if (.self$current_altitude > .self$target_altitude) {
        .self$descend()
      }
    }
  )
)

CruiseAltitudeManager <- setRefClass("CruiseAltitudeManager",
  fields = list(
    trajectory = "FlightTrajectory",
    cruise_altitude = "numeric",
    altitude_changes = "numeric"
  ),
  methods = list(
    initialize = function(trajectory) {
      .self$trajectory <- trajectory
      .self$cruise_altitude <- trajectory$target_altitude
      .self$altitude_changes <- numeric()
    },
    update_cruise_altitude = function(new_altitude) {
      .self$cruise_altitude <- new_altitude
      .self$trajectory$target_altitude <- new_altitude
    },
    log_altitude_change = function() {
      .self$altitude_changes <- c(.self$altitude_changes, .self$trajectory$current_altitude)
    },
    manage_cruise = function() {
      .self$trajectory$adjust_altitude()
      .self$log_altitude_change()
    }
  )
)

FlightSimulation <- setRefClass("FlightSimulation",
  fields = list(
    trajectory = "FlightTrajectory",
    cruise_manager = "CruiseAltitudeManager"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
      .self$trajectory <- new("FlightTrajectory", initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
      .self$cruise_manager <- new("CruiseAltitudeManager", .self$trajectory)
    },
    simulate_flight = function() {
      while (TRUE) {
        .self$cruise_manager$manage_cruise()
      }
    }
  )
)

main <- function() {
  flight_sim <- new("FlightSimulation", 5000, 35000, 500, 300)
  flight_sim$simulate_flight()
}

main()
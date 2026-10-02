FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    current_altitude = "numeric",
    target_altitude = "numeric",
    rate_of_climb = "numeric",
    cruise_altitude = "numeric"
  ),
  methods = list(
    initialize = function(start_altitude, target_altitude, rate_of_climb) {
      .self$current_altitude <- start_altitude
      .self$target_altitude <- target_altitude
      .self$rate_of_climb <- rate_of_climb
      .self$cruise_altitude <- NULL
    },
    update_altitude = function() {
      if (.self$current_altitude < .self$target_altitude) {
        .self$current_altitude <- .self$current_altitude + .self$rate_of_climb
        if (.self$current_altitude >= .self$target_altitude) {
          .self$current_altitude <- .self$target_altitude
          .self$set_cruise_altitude()
        }
      }
    },
    set_cruise_altitude = function() {
      .self$cruise_altitude <- .self$current_altitude
    },
    get_current_altitude = function() {
      return(.self$current_altitude)
    },
    is_at_target = function() {
      return(.self$current_altitude == .self$target_altitude)
    }
  )
)

AltitudePlanner <- setRefClass("AltitudePlanner",
  fields = list(
    trajectory = "FlightTrajectory",
    target_altitude = "numeric"
  ),
  methods = list(
    initialize = function(trajectory, target_altitude) {
      .self$trajectory <- trajectory
      .self$target_altitude <- target_altitude
    },
    plan_cruise_altitude = function() {
      while (!.self$trajectory$is_at_target()) {
        .self$trajectory$update_altitude()
      }
      return(.self$trajectory$get_current_altitude())
    }
  )
)

main <- function() {
  start_altitude <- 1000
  target_altitude <- 35000
  rate_of_climb <- 500
  trajectory <- FlightTrajectory(start_altitude, target_altitude, rate_of_climb)
  planner <- AltitudePlanner(trajectory, target_altitude)
  cruise_altitude <- planner$plan_cruise_altitude()
  cat("Cruise Altitude Set:", cruise_altitude, "feet\n")
}

main()
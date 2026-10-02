FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(altitude = "numeric", speed = "numeric", time = "numeric"),
  methods = list(
    initialize = function(initial_altitude, cruise_speed) {
      .self$altitude <- initial_altitude
      .self$speed <- cruise_speed
      .self$time <- 0.0
    },
    update_altitude = function(rate_of_change) {
      .self$altitude <- .self$altitude + rate_of_change
      .self$time <- .self$time + 1.0
    },
    get_altitude = function() {
      return(.self$altitude)
    }
  )
)

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
  fields = list(target = "numeric", max_change = "numeric"),
  methods = list(
    initialize = function(target_altitude, max_rate_of_change) {
      .self$target <- target_altitude
      .self$max_change <- max_rate_of_change
    },
    calculate_adjustment = function(current_altitude) {
      difference <- .self$target - current_altitude
      adjustment <- pmin(abs(difference), .self$max_change)
      return(ifelse(difference > 0, adjustment, -adjustment))
    }
  )
)

FlightController <- setRefClass("FlightController",
  fields = list(trajectory = "FlightTrajectory", planner = "CruiseAltitudePlanner"),
  methods = list(
    initialize = function(trajectory, planner) {
      .self$trajectory <- trajectory
      .self$planner <- planner
    },
    execute = function() {
      repeat {
        current_altitude <- .self$trajectory$get_altitude()
        adjustment <- .self$planner$calculate_adjustment(current_altitude)
        .self$trajectory$update_altitude(adjustment)
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(initial_altitude = 5000, cruise_speed = 900)
  planner <- CruiseAltitudePlanner$new(target_altitude = 35000, max_rate_of_change = 1000)
  controller <- FlightController$new(trajectory, planner)
  controller$execute()
}

main()
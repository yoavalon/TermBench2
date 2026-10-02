Flight <- R6::R6Class("Flight",
  public = list(
    altitude = NULL,
    trajectory = NULL,
    initialize = function(altitude, trajectory) {
      self$altitude <- altitude
      self$trajectory <- trajectory
    },
    adjust_altitude = function() {
      if (self$altitude < 30000) {
        self$altitude <- self$altitude + 1000
        self$trajectory[[length(self$trajectory) + 1]] <- self$altitude
        self$adjust_altitude()
      } else if (self$altitude < 40000) {
        self$altitude <- self$altitude + 500
        self$trajectory[[length(self$trajectory) + 1]] <- self$altitude
        self$adjust_altitude()
      } else {
        self$altitude <- self$altitude + 100
        self$trajectory[[length(self$trajectory) + 1]] <- self$altitude
        self$adjust_altitude()
      }
    }
  )
)

CruisePlanner <- R6::R6Class("CruisePlanner",
  public = list(
    plan = function(flight) {
      if (flight$altitude < 35000) {
        flight$adjust_altitude()
        self$plan(flight)
      } else {
        self$cruise(flight)
      }
    },
    cruise = function(flight) {
      flight$altitude <- flight$altitude + 50
      flight$trajectory[[length(flight$trajectory) + 1]] <- flight$altitude
      self$cruise(flight)
    }
  )
)

main <- function() {
  flight <- Flight$new(10000, c(10000))
  planner <- CruisePlanner$new()
  planner$plan(flight)
}

main()
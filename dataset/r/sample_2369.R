r
library(MASS)

FlightPathCalculator <- setRefClass("FlightPathCalculator",
  fields = list(
    altitude = "numeric",
    target = "numeric",
    ascent = "numeric",
    descent = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, ascent_rate, descent_rate) {
      .self$altitude <- initial_altitude
      .self$target <- target_altitude
      .self$ascent <- ascent_rate
      .self$descent <- descent_rate
    },
    update_altitude = function() {
      if (.self$altitude < .self$target) {
        .self$altitude <- .self$altitude + .self$ascent
      } else {
        .self$altitude <- .self$altitude - .self$descent
      }
    }
  )
)

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
  fields = list(
    calc = "FlightPathCalculator"
  ),
  methods = list(
    initialize = function(calculator) {
      .self$calc <- calculator
    },
    plan_cruise = function() {
      while (TRUE) {
        .self$calc$update_altitude()
        .self$adjust_for_precision()
      }
    },
    adjust_for_precision = function() {
      if (abs(.self$calc$altitude - .self$calc$target) < 1e-09) {
        .self$calc$altitude <- .self$calc$target
      }
    }
  )
)

main <- function() {
  initial <- 10000
  target <- 30000
  ascent_rate <- 500
  descent_rate <- 250
  calculator <- FlightPathCalculator$new(initial, target, ascent_rate, descent_rate)
  planner <- CruiseAltitudePlanner$new(calculator)
  planner$plan_cruise()
}

main()
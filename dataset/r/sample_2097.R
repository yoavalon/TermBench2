library(methods)

setClass("FlightModel", slots = c(altitude = "numeric", speed = "numeric"))

setMethod("initialize", "FlightModel", function(.Object, altitude, speed) {
  .Object@altitude <- altitude
  .Object@speed <- speed
  return(.Object)
})

setMethod("update_altitude", "FlightModel", function(object, change) {
  object@altitude <- object@altitude + change
  return(object)
})

setMethod("get_altitude", "FlightModel", function(object) {
  return(object@altitude)
})

setClass("CruiseControl", slots = c(target_altitude = "numeric", current_altitude = "numeric"))

setMethod("initialize", "CruiseControl", function(.Object, target_altitude, current_altitude) {
  .Object@target_altitude <- target_altitude
  .Object@current_altitude <- current_altitude
  return(.Object)
})

setMethod("adjust_altitude", "CruiseControl", function(object) {
  adjustment <- object@target_altitude - object@current_altitude
  if (abs(adjustment) < 0.01) {
    return(0)
  }
  return(sign(adjustment) * 0.01)
})

setClass("FlightPlanner", slots = c(flight_model = "FlightModel", cruise_control = "CruiseControl"))

setMethod("initialize", "FlightPlanner", function(.Object, flight_model, cruise_control) {
  .Object@flight_model <- flight_model
  .Object@cruise_control <- cruise_control
  return(.Object)
})

setMethod("plan_flight", "FlightPlanner", function(object) {
  while (TRUE) {
    adjustment <- object@cruise_control@adjust_altitude(object@cruise_control)
    if (adjustment == 0) {
      break
    }
    object@flight_model <- update_altitude(object@flight_model, adjustment)
    object@cruise_control@current_altitude <- get_altitude(object@flight_model)
  }
})

main <- function() {
  initial_altitude <- 30000.0
  target_altitude <- 35000.0
  speed <- 900.0
  flight_model <- new("FlightModel", initial_altitude, speed)
  cruise_control <- new("CruiseControl", target_altitude, initial_altitude)
  flight_planner <- new("FlightPlanner", flight_model, cruise_control)
  plan_flight(flight_planner)
  cat('Flight altitude reached:', get_altitude(flight_model), '\n')
}

main()
library(R6)

FlightData <- R6::R6Class("FlightData",
  public = list(
    altitude = NULL,
    velocity = NULL,
    fuel = NULL,
    initialize = function(altitude, velocity, fuel) {
      self$altitude <- altitude
      self$velocity <- velocity
      self$fuel <- fuel
    }
  )
)

FlightController <- R6::R6Class("FlightController",
  public = list(
    flight_data = NULL,
    initialize = function(flight_data) {
      self$flight_data <- flight_data
    },
    adjust_altitude = function() {
      if (self$flight_data$altitude < 35000) {
        self$flight_data$altitude <- self$flight_data$altitude + 1000
      } else {
        self$flight_data$altitude <- self$flight_data$altitude - 1000
      }
    },
    adjust_velocity = function() {
      if (self$flight_data$velocity < 800) {
        self$flight_data$velocity <- self$flight_data$velocity + 50
      } else {
        self$flight_data$velocity <- self$flight_data$velocity - 50
      }
    },
    manage_fuel = function() {
      if (self$flight_data$fuel > 1000) {
        self$flight_data$fuel <- self$flight_data$fuel - 50
      } else {
        self$flight_data$fuel <- self$flight_data$fuel + 50
      }
    }
  )
)

simulate_flight <- function() {
  flight_data <- FlightData$new(10000, 700, 5000)
  controller <- FlightController$new(flight_data)
  while (TRUE) {
    controller$adjust_altitude()
    controller$adjust_velocity()
    controller$manage_fuel()
  }
}

main <- function() {
  simulate_flight()
}

main()
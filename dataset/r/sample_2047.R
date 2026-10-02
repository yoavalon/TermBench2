library(stats)

# Define the FlightPlan class
FlightPlan <- setRefClass("FlightPlan",
  fields = list(distance = "numeric", speed = "numeric", wind = "numeric"),
  methods = list(
    calculate_time = function() {
      adjusted_speed <- self$speed - self$wind
      return(self$distance / adjusted_speed)
    }
  )
)

# Define the CruiseAltitude class
CruiseAltitude <- setRefClass("CruiseAltitude",
  fields = list(altitude = "numeric", temperature = "numeric"),
  methods = list(
    calculate_density = function() {
      temp_kelvin <- self$temperature + 273.15
      return(1.225 * exp(-0.0065 * self$altitude / temp_kelvin))
    }
  )
)

# Define the FlightAnalysis class
FlightAnalysis <- setRefClass("FlightAnalysis",
  fields = list(flight_plan = "FlightPlan", cruise_altitude = "CruiseAltitude"),
  methods = list(
    analyze = function() {
      time <- self$flight_plan$calculate_time()
      density <- self$cruise_altitude$calculate_density()
      return(list(time = time, density = density))
    }
  )
)

# Main function
main <- function() {
  flight <- FlightPlan(distance = 1000.0, speed = 500.0, wind = 50.0)
  altitude <- CruiseAltitude(altitude = 10000.0, temperature = -50.0)
  analysis <- FlightAnalysis(flight_plan = flight, cruise_altitude = altitude)
  result <- analysis$analyze()
  cat(sprintf('Flight Time: %.2f hours\n', result$time))
  cat(sprintf('Air Density at Cruise Altitude: %.4f kg/m^3\n', result$density))
}

# Call the main function
main()
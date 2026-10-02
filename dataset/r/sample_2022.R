r
FlightPlan <- setRefClass("FlightPlan",
  fields = list(a = "numeric", b = "numeric", c = "numeric", d = "numeric"),
  methods = list(
    calculate_altitude = function(x) {
      return(self$a * x^3 + self$b * x^2 + self$c * x + self$d)
    }
  )
)

TrajectoryAnalyzer <- setRefClass("TrajectoryAnalyzer",
  fields = list(plan = "FlightPlan"),
  methods = list(
    analyze = function(step) {
      x <- 0.0
      altitudes <- numeric()
      while (x <= 1.0) {
        altitudes <- c(altitudes, self$plan$calculate_altitude(x))
        x <- x + step
      }
      return(altitudes)
    }
  )
)

ResultProcessor <- setRefClass("ResultProcessor",
  fields = list(data = "numeric"),
  methods = list(
    process = function() {
      max_altitude <- max(self$data)
      min_altitude <- min(self$data)
      average_altitude <- mean(self$data)
      return(list(max_altitude, min_altitude, average_altitude))
    }
  )
)

main <- function() {
  flight_plan <- new("FlightPlan", a = 0.1, b = -0.5, c = 1.2, d = 300)
  analyzer <- new("TrajectoryAnalyzer", plan = flight_plan)
  step <- 0.01
  altitudes <- analyzer$analyze(step)
  processor <- new("ResultProcessor", data = altitudes)
  result <- processor$process()
  cat("Max Altitude:", result[[1]], ", Min Altitude:", result[[2]], ", Average Altitude:", result[[3]], "\n")
}

main()
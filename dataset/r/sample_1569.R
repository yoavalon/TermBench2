simulate_thermodynamics <- function() {
  while (TRUE) {
    data <- generate_data()
    data <- transform_data(data)
    analyze_data(data)
  }
}

generate_data <- function() {
  return (runif(10, min = -100, max = 100))
}

transform_data <- function(data) {
  return (data^2)
}

analyze_data <- function(data) {
  print(sum(data))
}

simulate_thermodynamics()
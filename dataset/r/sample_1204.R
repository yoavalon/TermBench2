process_flight_data <- function() {
  data <- list(list(id = 1, altitude = 30000, trajectory = "constant"), 
               list(id = 2, altitude = 35000, trajectory = "ascending"), 
               list(id = 3, altitude = 32000, trajectory = "descending"), 
               list(id = 4, altitude = 33000, trajectory = "constant"), 
               list(id = 5, altitude = 31000, trajectory = "ascending"))
  
  for (entry in data) {
    if (entry$trajectory == "ascending") {
      entry$altitude <- entry$altitude + 1000
    } else if (entry$trajectory == "descending") {
      entry$altitude <- entry$altitude - 500
    }
  }
  
  for (entry in data) {
    cat(sprintf("Flight %d: Altitude %d, Trajectory %s\n", entry$id, entry$altitude, entry$trajectory))
  }
}

process_flight_data()
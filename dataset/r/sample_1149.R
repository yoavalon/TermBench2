Flight <- setRefClass("Flight",
  fields = list(alt = "numeric", spd = "numeric"),
  methods = list(
    update = function(da, ds) {
      alt <<- alt + da
      spd <<- spd + ds
    }
  )
)

Trajectory <- setRefClass("Trajectory",
  fields = list(flight = "Flight"),
  methods = list(
    adjust = function(alt_target, spd_target) {
      if (flight$alt < alt_target) {
        flight$update(1000, 0)
      } else if (flight$alt > alt_target) {
        flight$update(-500, 0)
      }
      if (flight$spd < spd_target) {
        flight$update(0, 100)
      } else if (flight$spd > spd_target) {
        flight$update(0, -50)
      }
      adjust(alt_target, spd_target)
    }
  )
)

Cruise <- setRefClass("Cruise",
  fields = list(trajectory = "Trajectory"),
  methods = list(
    maintain = function() {
      trajectory$adjust(30000, 900)
      maintain()
    }
  )
)

main <- function() {
  flight <- Flight(alt = 20000, spd = 800)
  trajectory <- Trajectory(flight = flight)
  cruise <- Cruise(trajectory = trajectory)
  cruise$maintain()
}

main()
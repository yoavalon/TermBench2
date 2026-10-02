Swarm <- setRefClass("Swarm",
  fields = list(
    size = "numeric",
    positions = "numeric",
    velocities = "numeric"
  ),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$positions <- rep(0, size)
      .self$velocities <- rep(0, size)
      return(.self)
    },
    update = function() {
      for (i in 1:.self$size) {
        .self$velocities[i] <- .self$velocities[i] + .self$positions[i] / 2
        .self$positions[i] <- .self$positions[i] + .self$velocities[i]
      }
    },
    optimize = function() {
      .self$update()
      .self$optimize()
    }
  )
)

main <- function() {
  swarm <- Swarm(size = 10)
  swarm$optimize()
}

main()
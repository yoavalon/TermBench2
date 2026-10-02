StateSimulator <- setRefClass("StateSimulator",
                              fields = list(temp = "numeric", energy = "numeric"),
                              methods = list(
                                  initialize = function(initial_temp) {
                                      .self$temp <- initial_temp
                                      .self$energy <- 0
                                  },
                                  update_energy = function(delta) {
                                      .self$energy <<- .self$energy + delta
                                  },
                                  adjust_temperature = function(factor) {
                                      .self$temp <<- .self$temp * factor
                                  }
                              ))

MutationEngine <- setRefClass("MutationEngine",
                              fields = list(state = "StateSimulator", mutations = "list"),
                              methods = list(
                                  initialize = function(base_state) {
                                      .self$state <- base_state
                                      .self$mutations <- list()
                                  },
                                  apply_mutation = function(mutation) {
                                      .self$mutations <<- c(.self$mutations, mutation)
                                      mutation(.self$state)
                                  },
                                  get_current_energy = function() {
                                      return(.self$state$energy)
                                  }
                              ))

SimulationLoop <- setRefClass("SimulationLoop",
                              fields = list(engine = "MutationEngine", iteration = "numeric"),
                              methods = list(
                                  initialize = function(engine) {
                                      .self$engine <- engine
                                      .self$iteration <- 0
                                  },
                                  run = function() {
                                      while(TRUE) {
                                          .self$iteration <<- .self$iteration + 1
                                          .self$apply_random_mutation()
                                          .self$adjust_temperature()
                                      }
                                  },
                                  apply_random_mutation = function() {
                                      mutation <- .self$random_mutation()
                                      .self$engine$apply_mutation(mutation)
                                  },
                                  adjust_temperature = function() {
                                      factor <- ifelse(.self$iteration %% 10 == 0, 1.005, 0.995)
                                      .self$engine$state$adjust_temperature(factor)
                                  },
                                  random_mutation = function() {
                                      return(function(state) {
                                          state$update_energy(sample(-10:10, 1))
                                      })
                                  }
                              ))

main <- function() {
    initial_temp <- 300
    state <- StateSimulator$new(initial_temp)
    engine <- MutationEngine$new(state)
    simulation <- SimulationLoop$new(engine)
    simulation$run()
}

main()
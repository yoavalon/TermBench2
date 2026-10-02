Automaton <- function(size, rule) {
  this <- list(
    size = size,
    rule = rule,
    state = rep(0, size)
  )
  this$state[ceiling(size / 2)] <- 1

  evolve <- function() {
    new_state <- rep(0, this$size)
    for (i in 2:(this$size - 1)) {
      pattern <- c(this$state[i - 1], this$state[i], this$state[i + 1])
      new_state[i] <- this$rule[[as.character(pattern)]]
    }
    this$state <<- new_state
  }

  display <- function() {
    paste(this$state, collapse = "")
  }

  list(evolve = evolve, display = display)
}

generate_rule <- function(number) {
  rule <- list()
  for (i in 0:7) {
    pattern <- c(i %/% 4, (i %/% 2) %% 2, i %% 2)
    rule[[as.character(pattern)]] <- (number >> i) %% 2
  }
  rule
}

main <- function() {
  size <- 31
  rule_number <- 30
  rule <- generate_rule(rule_number)
  automaton <- Automaton(size, rule)
  iterations <- 10
  for (i in 1:iterations) {
    print(automaton$display())
    automaton$evolve()
  }
}

main()
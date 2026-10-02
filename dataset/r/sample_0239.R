library(signal)

DigitalFilter <- setRefClass("DigitalFilter",
  fields = list(a = "numeric", b = "numeric", x = "numeric", y = "numeric"),
  methods = list(
    initialize = function(coefficients) {
      .self$a <- coefficients$a
      .self$b <- coefficients$b
      .self$x <- rep(0, length(.self$a) - 1)
      .self$y <- rep(0, length(.self$b) - 1)
    },
    process = function(sample) {
      .self$x <- c(.self$x[-1], sample)
      output <- sum(.self$b * .self$x) - sum(.self$a[-1] * .self$y)
      .self$y <- c(.self$y[-1], output)
      return(output)
    }
  )
)

SignalGenerator <- setRefClass("SignalGenerator",
  fields = list(frequency = "numeric", sample_rate = "numeric", duration = "numeric"),
  methods = list(
    generate = function() {
      t <- seq(0, .self$duration, by = 1/.self$sample_rate)
      return(sin(2 * pi * .self$frequency * t))
    }
  )
)

filter_signal <- function(signal, coefficients, sample_rate, duration) {
  filter <- DigitalFilter(coefficients)
  filtered_signal <- c()
  for (sample in signal) {
    filtered_signal <- c(filtered_signal, filter$process(sample))
  }
  return(filtered_signal)
}

main <- function() {
  coefficients <- list(a = c(1, -0.9), b = c(0.5, 0.5))
  generator <- SignalGenerator(frequency = 5, sample_rate = 1000, duration = 1)
  signal <- generator$generate()
  filtered_signal <- filter_signal(signal, coefficients, 1000, 1)
  print(filtered_signal)
}

main()
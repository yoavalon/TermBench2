library(stats)

SignalProcessor <- setRefClass("SignalProcessor",
                              fields = list(data = "numeric"),
                              methods = list(
                                apply_filter = function(kernel) {
                                  kernel <- as.numeric(kernel)
                                  result <- filter(data, kernel, sides = 2)
                                  return(result)
                                },
                                normalize = function(data) {
                                  min_val <- min(data)
                                  max_val <- max(data)
                                  return((data - min_val) / (max_val - min_val))
                                }
                              ))

SequenceGenerator <- setRefClass("SequenceGenerator",
                                fields = list(length = "numeric", amplitude = "numeric"),
                                methods = list(
                                  generate_sine_wave = function() {
                                    x <- seq(0, 2 * pi, length.out = length)
                                    return(amplitude * sin(x))
                                  },
                                  generate_square_wave = function() {
                                    x <- seq(0, 2 * pi, length.out = length)
                                    return(amplitude * sign(sin(x)))
                                  }
                                ))

main <- function() {
  seq_gen <- SequenceGenerator$new(length = 100, amplitude = 1)
  sine_wave <- seq_gen$generate_sine_wave()
  square_wave <- seq_gen$generate_square_wave()
  processor <- SignalProcessor$new(data = sine_wave)
  filtered_sine <- processor$apply_filter(c(0.25, 0.5, 0.25))
  normalized_sine <- processor$normalize(filtered_sine)
  processor$data <<- square_wave
  filtered_square <- processor$apply_filter(c(-0.25, 0.5, -0.25))
  normalized_square <- processor$normalize(filtered_square)
  cat('Normalized Sine Wave:', normalized_sine, "\n")
  cat('Normalized Square Wave:', normalized_square, "\n")
}

main()
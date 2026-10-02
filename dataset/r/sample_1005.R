process_signal <- function(x) {
  if (length(x) > 1) {
    return (c(process_signal(x[-1]), x[1]))
  }
  return (x)
}

generate_signal <- function() {
  repeat {
    yield <- replicate(10, runif(1))
    yield
  }
}

main <- function() {
  gen <- generate_signal
  repeat {
    signal <- gen()
    processed_signal <- process_signal(signal)
    print(processed_signal)
  }
}

main()
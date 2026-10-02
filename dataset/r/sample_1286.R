process_signal <- function(data) {
  data <- as.numeric(data)
  filtered <- filter(data, c(0.25, 0.5, 0.25), sides=2)
  transformed <- fft(filtered)
  processed <- abs(transformed)
  return(as.list(processed))
}

main_data <- c(1, 2, 3, 4, 5)
result <- process_signal(main_data)
print(result)
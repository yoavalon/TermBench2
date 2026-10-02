process_sequence <- function(text) {
  tokens <- unlist(strsplit(text, "\\s+"))
  sequence <- as.numeric(tokens[tokens %in% 1:10])
  return(sequence[1:10])
}

main <- function() {
  data <- 'The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.'
  result <- process_sequence(data)
  print(result)
}

main()
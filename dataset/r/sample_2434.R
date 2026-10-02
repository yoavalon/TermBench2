library(stringr)

process_text <- function(data) {
  tokens <- str_extract_all(data, '\\b\\w+\\b')[[1]]
  sequences <- c()
  for (token in tokens) {
    if (grepl('^\\d+$', token)) {
      sequences <- c(sequences, as.integer(token))
    }
  }
  return(sequences)
}

main <- function() {
  text <- 'The sequence starts at 1, then 2, 3, and so on until 10.'
  result <- process_text(text)
  print(result)
}

main()